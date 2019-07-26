import random
import numpy as np
from matplotlib import pyplot
import csv

def combine_csv(path, csv, csv_1, csv_2, csv_3, csv_4):
    fout = open((path+csv+'.csv'),"w+")
    for line in open(path+csv_1+'.csv'):
        fout.write(line)
    for line in open(path+csv_2+'.csv'):
        fout.write(line)
    for line in open(path+csv_3+'.csv'):
        fout.write(line)
    for line in open(path+csv_4+'.csv'):
        fout.write(line)

def combine_csv_t(path, csv, csv_1, csv_2):
    fout = open((path+csv+'.csv'),"w+")
    for line in open(path+csv_1+'.csv'):
        fout.write(line)
    for line in open(path+csv_2+'.csv'):
        fout.write(line)


def process_month(path, month, labels):
    li = read_in(path)
    # x1 = [float(v[0]) for v in li]

    # pyplot.figure()
    #
    # pyplot.plot(y1,x1, 'ro')
    # pyplot.ylabel('Likelihood')
    # pyplot.xlabel(month + ' temperature ($^\circ$ C) :')
    # pyplot.savefig(path + '_points.png')

    pyplot.figure()
    y1  = [float(v[0])  for v in li]
    y2  = [float(v[1])  for v in li]
    y3  = [float(v[2])  for v in li]
    y4  = [float(v[3])  for v in li]
    y5  = [float(v[4])  for v in li]
    y6  = [float(v[5])  for v in li]
    y7  = [float(v[6])  for v in li]
    y8  = [float(v[7])  for v in li]
    y9  = [float(v[8]) for v in li]
    y10 = [float(v[9]) for v in li]
    y11 = [float(v[10]) for v in li]
    y12 = [float(v[11]) for v in li]
    y13 = [float(v[12]) for v in li]

    ys = [y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13]

    plot_hist(ys, month, path, labels)

    plot_hist_comb(ys, month, path, labels)

    return [
    (np.mean(y1), np.std(y1)),
    (np.mean(y2), np.std(y2)),
    (np.mean(y3), np.std(y3)),
    (np.mean(y4), np.std(y4)),
    (np.mean(y5), np.std(y5)),
    (np.mean(y6), np.std(y6)),
    (np.mean(y7), np.std(y7)),
    (np.mean(y8), np.std(y8)),
    (np.mean(y9), np.std(y9)),
    (np.mean(y10), np.std(y10)),
    (np.mean(y11), np.std(y11)),
    (np.mean(y12), np.std(y12)),
    (np.mean(y13), np.std(y13))
    ]

def plot_hist_comb(ys, month, path, labels):

    y_reduced = reduce(list.__add__, ys)

    y_min = int(min(y_reduced) - 1.0)
    y_max = int(max(y_reduced) + 1.0)

    pyplot.figure()

    pyplot.ylim(0,4200)
    pyplot.xlim(y_min, y_max)
    pyplot.xlabel(month + ' temperature ($^\circ$ C)')
    pyplot.ylabel('Frequency')
    pyplot.tight_layout(rect=[0,0,0.75,1])

    for val in range(0, len(ys)):
        pyplot.hist(ys[val], alpha=0.5, label=labels[val])
    pyplot.legend(bbox_to_anchor=(1.04,1), loc='upper left')
    pyplot.subplots_adjust(right=0.7)
    pyplot.savefig(path + '_hist_comb.png', bbox_inches="tight")
    pyplot.figure()

def plot_hist(ys, month, path, labels):

    y_reduced = reduce(list.__add__, ys)

    y_min = int(min(y_reduced) - 1.0)
    y_max = int(max(y_reduced) + 1.0)

    for val in range(0, len(ys)):
        pyplot.figure()
        pyplot.ylim(0,4200)
        pyplot.hist(ys[val], alpha=0.5, label='Temperature')
        pyplot.xlim(y_min, y_max)
        pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[val])
        pyplot.ylabel('Frequency')
        pyplot.legend(loc='upper right')
        pyplot.savefig(path + '_hist_'+str(val+1)+'.png')
        pyplot.tight_layout()
        pyplot.figure()

def calculate_global_temperature_change(extra):

    months = [
    read_in('./months/jan/comb'+extra),
    read_in('./months/feb/comb'+extra),
    read_in('./months/mar/comb'+extra),
    read_in('./months/apr/comb'+extra),
    read_in('./months/may/comb'+extra),
    read_in('./months/jun/comb'+extra),
    read_in('./months/jul/comb'+extra),
    read_in('./months/aug/comb'+extra),
    read_in('./months/sep/comb'+extra),
    read_in('./months/oct/comb'+extra),
    read_in('./months/nov/comb'+extra),
    read_in('./months/dec/comb'+extra)
    ]
    global_stats = []
    temp         = []
    for time_period in range(0, 13):
        for month in range(0, len(months)):
            for i in range(0, len(months[month])):
                ys = float(months[month][i][time_period])
                temp.append(ys)


        global_stats += [(np.mean(temp), np.std(temp))]
        temp = []

    return global_stats


def read_in(csv_path):
    data = csv.reader(open(csv_path + '.csv', 'rt'))
    li = [tuple(row) for row in data]
    li = li[:len(li)-1]
    return li

def graph_vals(path, labels, month_vals, month_name, display_bar):
    x_pos = np.arange(len(labels))
    means = [mean[0] for mean in month_vals]
    errors = [std[1] for std in month_vals]
    fig, ax = pyplot.subplots()
    if(display_bar):
        ax.bar(
            x_pos,
            means,
            yerr=errors,
            align='center',
            alpha=0.5,
            ecolor='black',
            capsize=10)
    else:
        ax.bar(
            x_pos,
            means,
            align='center')

    ax.set_ylabel('Temperature ($^\circ$ C)')
    ax.set_xticks(x_pos)
    ax.set_xticklabels(labels, rotation='vertical', fontsize=16)
    ax.set_title(month_name + ' temperature change over time.')
    ax.yaxis.grid(True)

    # Save the figure and show
    pyplot.tight_layout()
    pyplot.savefig(path+'aggregate.png')

def trace_posterior():
    li = read_in('./gaussian/trace_posterior')
    y = [float(v[0]) for v in li]

    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label='samples from the posterior', bins=100)
    pyplot.xlabel('$\Theta$')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/trace_posterior_hist.png')
    pyplot.figure()

    y = y[500:]
    pyplot.hist(y, alpha=0.5, label='samples from the posterior')
    pyplot.xlabel('$\Theta$ with burn in of 500 samples')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/trace_posterior_hist_burnin.png')
    pyplot.figure()

def smc_posterior():
    li = read_in('./gaussian/smc_posterior')
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]

    pyplot.figure()
    pyplot.plot(y,x, 'ro')
    pyplot.ylabel('likelihood')
    pyplot.xlabel('$\Theta$')
    pyplot.savefig('./gaussian/smc_posterior_points.png')
    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label='samples from the posterior')
    pyplot.xlabel('$\Theta$')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/smc_posterior_hist.png')
    pyplot.figure()

def is_posterior():
    li = read_in('./gaussian/importance_sampling')
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]

    pyplot.figure()
    pyplot.plot(y,x, 'ro', label='samples from the posterior')
    pyplot.ylabel('likelihood')
    pyplot.legend(loc='upper left')
    pyplot.xlabel('$\Theta$')
    pyplot.savefig('./gaussian/is_posterior_points.png')
    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label='samples from the prior')
    pyplot.xlabel('$\Theta$')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/is_posterior_hist.png')
    pyplot.figure()

labels = ['1756 - 1776',
          '1776 - 1796',
          '1796 - 1816',
          '1816 - 1836',
          '1836 - 1856',
          '1856 - 1876',
          '1876 - 1896',
          '1896 - 1916',
          '1916 - 1936',
          '1936 - 1936',
          '1956 - 1976',
          '1976 - 1996',
          '1996 - 2016']

smc_posterior()
trace_posterior()
is_posterior()


combine_csv('./months/jan/', 'comb_smc', 'jan_5', 'jan_6', 'jan_3', 'jan_4')
combine_csv('./months/feb/', 'comb_smc', 'feb_5', 'feb_6', 'feb_3', 'feb_4')
combine_csv('./months/mar/', 'comb_smc', 'mar_5', 'mar_6', 'mar_3', 'mar_4')
combine_csv('./months/apr/', 'comb_smc', 'apr_5', 'apr_6', 'apr_3', 'apr_4')
combine_csv('./months/may/', 'comb_smc', 'may_5', 'may_6', 'may_3', 'may_4')
combine_csv('./months/jun/', 'comb_smc', 'jun_5', 'jun_6', 'jun_3', 'jun_4')
combine_csv('./months/jul/', 'comb_smc', 'jul_5', 'jul_6', 'jul_3', 'jul_4')
combine_csv('./months/aug/', 'comb_smc', 'aug_5', 'aug_6', 'aug_3', 'aug_4')
combine_csv('./months/sep/', 'comb_smc', 'sep_5', 'sep_6', 'sep_3', 'sep_4')
combine_csv('./months/oct/', 'comb_smc', 'oct_5', 'oct_6', 'oct_3', 'oct_4')
combine_csv('./months/nov/', 'comb_smc', 'nov_5', 'nov_6', 'nov_3', 'nov_4')
combine_csv('./months/dec/', 'comb_smc', 'dec_5', 'dec_6', 'dec_3', 'dec_4')

combine_csv_t('./months/jan/', 'comb_tmcmc', 'jan_1', 'jan_2')
combine_csv_t('./months/feb/', 'comb_tmcmc', 'feb_1', 'feb_2')
combine_csv_t('./months/mar/', 'comb_tmcmc', 'mar_1', 'mar_2')
combine_csv_t('./months/apr/', 'comb_tmcmc', 'apr_1', 'apr_2')
combine_csv_t('./months/may/', 'comb_tmcmc', 'may_1', 'may_2')
combine_csv_t('./months/jun/', 'comb_tmcmc', 'jun_1', 'jun_2')
combine_csv_t('./months/jul/', 'comb_tmcmc', 'jul_1', 'jul_2')
combine_csv_t('./months/aug/', 'comb_tmcmc', 'aug_1', 'aug_2')
combine_csv_t('./months/sep/', 'comb_tmcmc', 'sep_1', 'sep_2')
combine_csv_t('./months/oct/', 'comb_tmcmc', 'oct_1', 'oct_2')
combine_csv_t('./months/nov/', 'comb_tmcmc', 'nov_1', 'nov_2')
combine_csv_t('./months/dec/', 'comb_tmcmc', 'dec_1', 'dec_2')


labels = ['1756 - 1776',
          '1776 - 1796',
          '1796 - 1816',
          '1816 - 1836',
          '1836 - 1856',
          '1856 - 1876',
          '1876 - 1896',
          '1896 - 1916',
          '1916 - 1936',
          '1936 - 1936',
          '1956 - 1976',
          '1976 - 1996',
          '1996 - 2016']


jan = process_month('./months/jan/comb_smc', 'January'  , labels)
feb = process_month('./months/feb/comb_smc', 'Feburary' , labels)
mar = process_month('./months/mar/comb_smc', 'March'    , labels)
apr = process_month('./months/apr/comb_smc', 'April'    , labels)
may = process_month('./months/may/comb_smc', 'May'      , labels)
jun = process_month('./months/jun/comb_smc', 'June'     , labels)
jul = process_month('./months/jul/comb_smc', 'July'     , labels)
aug = process_month('./months/aug/comb_smc', 'August'   , labels)
sep = process_month('./months/sep/comb_smc', 'September', labels)
oct = process_month('./months/oct/comb_smc', 'October'  , labels)
nov = process_month('./months/nov/comb_smc', 'November' , labels)
dec = process_month('./months/dec/comb_smc', 'December' , labels)


graph_vals('./months/jan/', labels, jan, 'January'  , True)
graph_vals('./months/feb/', labels, feb, 'Feburary' , True)
graph_vals('./months/mar/', labels, mar, 'March'    , True)
graph_vals('./months/apr/', labels, apr, 'April'    , True)
graph_vals('./months/may/', labels, may, 'May'      , True)
graph_vals('./months/jun/', labels, jun, 'June'     , True)
graph_vals('./months/jul/', labels, jul, 'July'     , True)
graph_vals('./months/aug/', labels, aug, 'August'   , True)
graph_vals('./months/sep/', labels, sep, 'September', True)
graph_vals('./months/oct/', labels, oct, 'October'  , True)
graph_vals('./months/nov/', labels, nov, 'November' , True)
graph_vals('./months/dec/', labels, dec, 'December' , True)

graph_vals("./smc_", labels, calculate_global_temperature_change("_smc"), "Global", False)

jan = process_month('./months/jan/comb_tmcmc', 'January'  , labels)
feb = process_month('./months/feb/comb_tmcmc', 'Feburary' , labels)
mar = process_month('./months/mar/comb_tmcmc', 'March'    , labels)
apr = process_month('./months/apr/comb_tmcmc', 'April'    , labels)
may = process_month('./months/may/comb_tmcmc', 'May'      , labels)
jun = process_month('./months/jun/comb_tmcmc', 'June'     , labels)
jul = process_month('./months/jul/comb_tmcmc', 'July'     , labels)
aug = process_month('./months/aug/comb_tmcmc', 'August'   , labels)
sep = process_month('./months/sep/comb_tmcmc', 'September', labels)
oct = process_month('./months/oct/comb_tmcmc', 'October'  , labels)
nov = process_month('./months/nov/comb_tmcmc', 'November' , labels)
dec = process_month('./months/dec/comb_tmcmc', 'December' , labels)

graph_vals('./months/jan/tmcmc_', labels, jan, 'January'  , True)
graph_vals('./months/feb/tmcmc_', labels, feb, 'Feburary' , True)
graph_vals('./months/mar/tmcmc_', labels, mar, 'March'    , True)
graph_vals('./months/apr/tmcmc_', labels, apr, 'April'    , True)
graph_vals('./months/may/tmcmc_', labels, may, 'May'      , True)
graph_vals('./months/jun/tmcmc_', labels, jun, 'June'     , True)
graph_vals('./months/jul/tmcmc_', labels, jul, 'July'     , True)
graph_vals('./months/aug/tmcmc_', labels, aug, 'August'   , True)
graph_vals('./months/sep/tmcmc_', labels, sep, 'September', True)
graph_vals('./months/oct/tmcmc_', labels, oct, 'October'  , True)
graph_vals('./months/nov/tmcmc_', labels, nov, 'November' , True)
graph_vals('./months/dec/tmcmc_', labels, dec, 'December' , True)

graph_vals("./tmcmc_", labels, calculate_global_temperature_change("_tmcmc"), "Global", False)
