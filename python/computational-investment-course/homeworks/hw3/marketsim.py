#!/usr/bin/env python

import csv
import sys
import copy
import datetime as dt
import pandas as pd
import numpy as np
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.DataAccess as da

import collections
from datetime import date
from operator import itemgetter


def get_orders(f):
    trades = []
    with open(f, 'r') as csvfile:
        csvcontent = csv.reader(csvfile, quotechar=',')
        for i in csvcontent:
            # [ date, code, operation, value ]
            row = [
                dt.datetime(int(i[0]), int(i[1]), int(i[2])),
                i[3], i[4], float(i[5])
            ]
            trades.append(row)

    trades.sort(key=itemgetter(0))

    return trades


def read_yahoo_data(start_date, end_date, ls_symbols, ls_keys=['close']):
    ldt_timestamps = du.getNYSEdays(start_date, end_date, dt.timedelta(hours=16))
    dataobj = da.DataAccess('Yahoo')
    return dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)[0].sort(axis=1)


def unique_codes(trades):
    codes = []
    for trade in trades:
        if not trade[1] in codes:
            codes.append(trade[1])

    codes.sort()
    return codes


def portfolio_by_date(start_date, end_date, codes, trades):
    ny_days = du.getNYSEdays(start_date, end_date, dt.timedelta(hours=00))
    portfolio_codes = collections.OrderedDict()

    # {"AAPL": [0, 0, 0, ...], "GOOG": [0, 0, ...]}
    for x in codes:
        portfolio_codes[x] = np.zeros(len(ny_days))

    portfolio_trades = copy.deepcopy(portfolio_codes)

    for curr_trade in trades:
        if curr_trade[2].lower() == "sell":
            value = curr_trade[-1]
        else:
            value = curr_trade[-1] * -1

        index = ny_days.index(curr_trade[0])
        stock = curr_trade[1]

        portfolio_codes[stock][index] += value

        for i in range(index, len(portfolio_trades[stock])):
            portfolio_trades[stock][i] += value

    df_portfolio = pd.DataFrame(portfolio_codes).sort(axis=1)
    df_ptrades = pd.DataFrame(portfolio_trades).sort(axis=1)

    return df_portfolio, df_ptrades


def write_values_file(f, money_by_date):
    with open(f, 'w+') as csvfile:
        for timeframe in money_by_date:
            csvfile.write("%s, %s, %s, %s\n" % (
                timeframe[0].year,
                timeframe[0].month,
                timeframe[0].day,
                int(timeframe[-1]),
            ))


def money_by_date(start_date, end_date, daily_values, initial_money, add_date=False, cumulative=False):
    money = []
    current_money = initial_money

    i = 0
    for curr_date in du.getNYSEdays(start_date, end_date+dt.timedelta(1), dt.timedelta(hours=16)):
        if not cumulative:
            current_money = 0

        for value in daily_values[i]:
            current_money += value

        if add_date:
            money.append([curr_date, current_money])
        else:
            money.append([current_money])

        i += 1

    return np.array(money)


def add_dates_to(ary):
    i = 0
    money = []

    for curr_date in du.getNYSEdays(start_date, end_date+dt.timedelta(1), dt.timedelta(hours=16)):
        money.append([curr_date, ary[i]])
        i+=1

    return money

if __name__ == '__main__':
    initial_money = float(sys.argv[1])
    orders_file   = sys.argv[2]
    values_file   = sys.argv[3]

    trades = get_orders(orders_file)

    start_date = trades[0][0]
    end_date   = trades[-1][0]

    codes = unique_codes(trades)

    # Needed to consider 1 day more to actually use the last date...
    data                        =   read_yahoo_data(start_date, end_date+dt.timedelta(1), codes)
    portfolio, portfolio_trades = portfolio_by_date(start_date, end_date, codes, trades)

    daily_values_c = data.values * portfolio.values
    daily_values_s = (portfolio_trades.values * -1) * data.values

    moneyc = money_by_date(start_date, end_date, daily_values_c, initial_money, cumulative=True)
    moneys = money_by_date(start_date, end_date, daily_values_s, 0)

    money = add_dates_to(moneyc + moneys)

    write_values_file(values_file, money)
