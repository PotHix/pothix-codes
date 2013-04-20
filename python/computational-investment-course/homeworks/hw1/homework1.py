#!/hfe/ova/rai clguba
import os
import sys
import math
import datetime as dt

# QSTK Imports
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.tsutil as tsu
import QSTK.qstkutil.DataAccess as da

# Third Party Imports
import datetime as dt
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

def main():
    vol, daily_ret, sharpe, cum_ret = 0, 0, 0, 0
    opt_vol, opt_daily_ret, opt_sharpe, opt_cum_ret = vol, daily_ret, sharpe, cum_ret

    if len(sys.argv) < 2:
        dt_start = dt.datetime(2011,  1,  1)
        dt_end   = dt.datetime(2011, 12, 31)
        stocks   = ["AAPL", "GLD", "GOOG", "XOM"]
        allocs   = [0.4, 0.4, 0, 0.2]
    else:
        dt_start = dt.datetime.strptime(sys.argv[1], "%Y-%m-%d")
        dt_end   = dt.datetime.strptime(sys.argv[2], "%Y-%m-%d")
        stocks   = sys.argv[3].split(",")
        allocs   = map(lambda x: float(x), sys.argv[4].split(","))

    allocs = optimal_portfolio(dt_start, dt_end, stocks)

    print "=========================================================="
    print "Start Date: %s" % dt_start.strftime("%B %d, %Y")
    print "End Date: %s" % dt_end.strftime("%B %d, %Y")
    print "Symbols: %s" % stocks
    print "Optimal Allocations: %s" % allocs
    print "Sharpe Ratio: %s" % opt_sharpe
    print "Volatility (stdev of daily returns): %s" % opt_vol
    print "Average Daily Return: %s" % opt_daily_ret
    print "Cumulative Return: %s" % opt_cum_ret


def optimal_portfolio(dt_start, dt_end, stocks, allocs=[]):
    opt_sharpe, opt_allocs = float('-inf'), allocs

    for i1 in np.arange(0, 1.1, 0.1):

        for i2 in np.arange(0, 1.1, 0.1):

            for i3 in np.arange(0, 1.1, 0.1):

                for i4 in np.arange(0, 1.1, 0.1):
                    allocs = [i1, i2, i3, i4]

                    if not sum(allocs) == 1.0:
                        break

                    vol, daily_ret, sharpe, cum_ret = simulate(
                        dt_start, dt_end, stocks, allocs
                    )

                    # Good sharpe found! Optimal for now
                    if sharpe >= opt_sharpe:
                        opt_sharpe = sharpe
                        opt_allocs = allocs

    return opt_allocs

def simulate(dt_start, dt_end, ls_symbols, allocations):
    ################ Get the needed data
    dt_timeofday = dt.timedelta(hours=16)
    ldt_timestamps = du.getNYSEdays(dt_start, dt_end, dt_timeofday)

    qsdata = os.path.join(os.path.dirname(__file__), '..', 'fixtures')
    output = os.path.join(os.path.dirname(__file__), '..', 'output')
    data_obj = da.DataAccess('Yahoo')#, qsdata)

    ls_keys = ['close']

    ldf_data = data_obj.get_data(ldt_timestamps, ls_symbols, ls_keys)
    d_data = dict(zip(ls_keys, ldf_data))
    ################ Data ok

    trading_days = 252
    values = d_data["close"].values

    norm_values = values / values[0,:]
    allocated = norm_values * np.array(allocations)

    portfolio_cumulative_returns = allocated.sum(axis=1)

    padded_allocated  = np.concatenate((portfolio_cumulative_returns, [0]))
    shifted_allocated = np.concatenate(([portfolio_cumulative_returns[0]], portfolio_cumulative_returns))

    daily_returns = np.nan_to_num(padded_allocated/shifted_allocated - 1)[0:-1]

    means   = daily_returns.mean()
    std     = daily_returns.std()
    sharpe  = np.nan_to_num(means/std * math.sqrt(trading_days))
    cum_ret = portfolio_cumulative_returns[-1]

    return std, means, sharpe, cum_ret

if __name__ == '__main__':
    main()
