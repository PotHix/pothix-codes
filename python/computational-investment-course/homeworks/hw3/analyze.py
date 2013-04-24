#!/usr/bin/env python

import csv
import sys
import math
import numpy as np
import datetime as dt

# QSTK Imports
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.tsutil as tsu
import QSTK.qstkutil.DataAccess as da

import matplotlib.pyplot as plt


def read_values(f):
    values = []
    with open(f, 'r') as csvfile:
        csvcontent = csv.reader(csvfile, quotechar=',')
        for i in csvcontent:
            values.append([
                dt.datetime(int(i[0]), int(i[1]), int(i[2])),
                i[3]
            ])

    return values


def yahoo_read_data(comparison):
    ldt_timestamps = du.getNYSEdays(start_date, end_date+dt.timedelta(1), dt.timedelta(hours=16))
    data_obj = da.DataAccess('Yahoo')
    return data_obj.get_data(ldt_timestamps, comparison, ["close"])[0].values


def calculate_for(values):
    trading_days = 252
    values = values / values[0, :]

    # Estimate portfolio returns
    na_portrets = np.sum(values, axis=1)
    cum_ret = na_portrets[-1]
    tsu.returnize0(na_portrets)

    # Statistics to calculate
    stddev = np.std(na_portrets)
    daily_ret = np.mean(na_portrets)
    sharpe = (np.sqrt(trading_days) * daily_ret) / stddev

    # Return all the variables
    return na_portrets, stddev, daily_ret, sharpe, cum_ret


if __name__ == '__main__':
    values_file = sys.argv[1]
    comparison  = [sys.argv[2]]

    values = read_values(values_file)
    fund_values = np.array([[float(value[1])] for value in values])

    start_date = values[0][0]
    end_date   = values[-1][0]
    last_line  = "%s,%s,%s,%s" % (
        values[-1][0].year,
        values[-1][0].month,
        values[-1][0].day,
        values[-1][1].lstrip()
    )

    comp_values = yahoo_read_data(comparison)

    values_comp, stddev_comp, avgret_comp, sharpe_comp, return_comp = calculate_for(comp_values)
    values_fund, stddev_fund, avgret_fund, sharpe_fund, return_fund = calculate_for(fund_values)

    print "The final value of the portfolio using the sample file is -- %s" % last_line
    print ""
    print "Details of the Performance of the portfolio"
    print ""
    print "Data Range :  %s  to  %s" % (start_date, end_date)
    print ""
    print "Sharpe Ratio of Fund : %f" % sharpe_fund
    print "Sharpe Ratio of %s : %f" % (comparison[0], sharpe_comp)
    print ""
    print "Total Return of Fund : %f" % return_fund
    print "Total Return of %s : %f" % (comparison[0], return_comp)
    print ""
    print "Standard Deviation of Fund : %f" % stddev_fund
    print "Standard Deviation of %s : %f" % (comparison[0], stddev_comp)
    print ""
    print "Average Daily Return of Fund : %f" % avgret_fund
    print "Average Daily Return of %s : %f" % (comparison[0], avgret_comp)

    ldt_timestamps = du.getNYSEdays(start_date, end_date+dt.timedelta(1), dt.timedelta(hours=16))

    plt.plot(ldt_timestamps, values_fund, label='Portfolio')
    plt.plot(ldt_timestamps, values_comp, label=comparison[0])
    plt.legend()
    plt.ylabel('Returns')
    plt.xlabel('Date')
    plt.savefig('homework3.pdf', format='pdf')
