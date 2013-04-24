#!/usr/bin/python2

import os
import pandas as pd
import numpy as np
import math
import copy
import datetime as dt

# QSTK
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.DataAccess as da
import QSTK.qstkstudy.EventProfiler as ep


def find_events(ls_symbols, d_data):
    df_close = d_data['actual_close']

    # Duplicating and setting everything to NaN
    df_events = copy.deepcopy(df_close)
    df_events = df_events * np.NAN

    # All timestamps as datetimes
    ldt_timestamps = df_close.index

    for s_sym in ls_symbols:
        for i in range(1, len(ldt_timestamps)):
            price_today     = df_close[s_sym].ix[ldt_timestamps[i]]
            price_yesterday = df_close[s_sym].ix[ldt_timestamps[i - 1]]

            price = 5.00

            if price_today < price and price_yesterday >= price:
                df_events[s_sym].ix[ldt_timestamps[i]] = 1

                if i + 5 > len(ldt_timestamps):
                    sell_date = ldt_timestamps[-1]
                else:
                    sell_date = ldt_timestamps[i+5]

                trade(s_sym, ldt_timestamps[i], "Buy")
                trade(s_sym, sell_date, "Sell")

    return df_events


def trade(symbol, start_date, action, amount=100):
    f = "orders.csv"
    with open(f, 'a+b') as csvfile:
        csvfile.write("%s,%s,%s,%s,%s,%s,\n" % (
            start_date.year,
            start_date.month,
            start_date.day,
            symbol, action, amount,
        ))


if __name__ == '__main__':
    dt_start = dt.datetime(2008, 1, 1)
    dt_end = dt.datetime(2009, 12, 31)
    ldt_timestamps = du.getNYSEdays(dt_start, dt_end, dt.timedelta(hours=16))

    dataobj = da.DataAccess('Yahoo')
    ls_symbols = dataobj.get_symbols_from_list('sp5002012')
    ls_symbols.append('SPY')
    ls_keys = ['actual_close', 'close']

    ldf_data = dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)
    d_data = dict(zip(ls_keys, ldf_data))

    df_events = find_events(ls_symbols, d_data)

    for s_key in ls_keys:
        d_data[s_key] = d_data[s_key].fillna(method = 'ffill')
        d_data[s_key] = d_data[s_key].fillna(method = 'bfill')
        d_data[s_key] = d_data[s_key].fillna(1.0)

    print "Creating Study"

    ep.eventprofiler(df_events, d_data, i_lookback=20, i_lookforward=20,
                s_filename="MyEventStudy.pdf", b_market_neutral=True,
                b_errorbars=True)
