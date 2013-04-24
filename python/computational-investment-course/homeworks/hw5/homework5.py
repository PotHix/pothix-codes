#!/usr/bin/env python

import pandas as pd
import numpy as np
import datetime as dt
import matplotlib.pyplot as plt

# QSTK
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.DataAccess as da


def read_yahoo_data(start_date, end_date, ls_symbols, ls_keys=['close']):
    ldt_timestamps = du.getNYSEdays(start_date, end_date, dt.timedelta(hours=16))
    dataobj = da.DataAccess('Yahoo')
    return dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)[0].sort(axis=1)


def sma_chart(timestamps, data, lookback=20):
    sma = pd.rolling_mean(data, lookback)
    plt.plot(timestamps, data, label=ls_symbols[0])
    plt.plot(timestamps, sma, label="Moving AVG")
    plt.legend()
    plt.ylabel('Returns')
    plt.xlabel('Date')

    plt.savefig('homework5_sma.pdf', format='pdf')


def bollinger_chart(timestamps, data, lookback=20):
    sma = pd.rolling_mean(data, lookback)
    upper = sma + pd.rolling_std(data, lookback)
    lower = sma - pd.rolling_std(data, lookback)

    plt.plot(ldt_timestamps, data, label=ls_symbols[0])
    plt.plot(ldt_timestamps, sma, label="Moving AVG")
    plt.plot(ldt_timestamps, upper, label="upper band")
    plt.plot(ldt_timestamps, lower, label="lower band")
    plt.legend(loc=3)
    plt.ylabel('Returns')
    plt.xlabel('Date')

    plt.savefig('homework5_bollinger.pdf', format='pdf')


if __name__ == '__main__':
    lookback = 20

    start_date = dt.datetime(2010, 1, 1)
    end_date = dt.datetime(2010, 12, 31)
    ldt_timestamps = du.getNYSEdays(start_date, end_date, dt.timedelta(hours=16))
    ls_symbols = ["GOOG", "AAPL", "IBM", "MSFT"]

    stock_data = read_yahoo_data(start_date, end_date, ls_symbols)

    sma_chart(ldt_timestamps, stock_data, lookback)
    plt.clf()
    bollinger_chart(ldt_timestamps, stock_data, lookback)

    sma = pd.rolling_mean(stock_data, lookback)
    std = pd.rolling_std(stock_data, lookback)

    bol = (stock_data - sma) / std
    print bol.tail(5)
