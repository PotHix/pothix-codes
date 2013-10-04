#!/usr/bin/python2

import pandas as pd
import numpy as np
import copy
import datetime as dt

# QSTK
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.DataAccess as da
import QSTK.qstkstudy.EventProfiler as ep


def find_events(ls_symbols, d_data):
    lookback = 20
    df_close = d_data["close"]

    # Duplicating and setting everything to NaN
    df_events = copy.deepcopy(df_close)
    df_events = df_events * np.NAN

    # All timestamps as datetimes
    ldt_timestamps = df_close.index

    sma = pd.rolling_mean(df_close, lookback)
    std = pd.rolling_std(df_close, lookback)

    bol = (df_close - sma) / std

    for s_sym in ls_symbols[:-1]:
        spy = bol[ls_symbols[-1]]

        for i in range(1, len(ldt_timestamps)):
            price_today     = bol[s_sym].ix[ldt_timestamps[i]]
            price_yesterday = bol[s_sym].ix[ldt_timestamps[i - 1]]
            spy_today       = spy.ix[ldt_timestamps[i]]

            if price_today < -2.00 and price_yesterday >= -2.00 and spy_today >= 1.5:
                df_events[s_sym].ix[ldt_timestamps[i]] = 1

    return df_events


if __name__ == '__main__':
    dt_start = dt.datetime(2008, 1, 1)
    dt_end = dt.datetime(2009, 12, 31)
    ldt_timestamps = du.getNYSEdays(dt_start, dt_end, dt.timedelta(hours=16))

    dataobj = da.DataAccess('Yahoo')
    ls_symbols = dataobj.get_symbols_from_list('sp5002012')
    ls_symbols.append('SPY')
    ls_keys = ['close']

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
