import random
import numpy as np
from matplotlib import pyplot
import csv

def combine_csv(path, csv_1, csv_2, csv_3, csv_4):
    fout = open((path+"comb.csv"),"w+")
    for line in open(path+csv_1+'.csv'):
        fout.write(line)
    for line in open(path+csv_2+'.csv'):
        fout.write(line)
    for line in open(path+csv_3+'.csv'):
        fout.write(line)
    for line in open(path+csv_4+'.csv'):
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

def plot_hist(ys, month, path, labels):

    y_reduced = reduce(list.__add__, ys)

    y_min = int(min(y_reduced) - 1.0)
    y_max = int(max(y_reduced) + 1.0)

    for val in range(0, len(ys)):
        pyplot.figure()

        pyplot.hist(ys[val], alpha=0.5, label='Temperature')
        pyplot.xlim(y_min, y_max)
        pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[val])
        pyplot.ylabel('Frequency')
        pyplot.legend(loc='upper right')
        pyplot.savefig(path + '_hist_'+str(val+1)+'.png')
        pyplot.tight_layout()
        pyplot.figure()

def calculate_global_temperature_change():

    months = [
    read_in('./months/jan/comb'),
    read_in('./months/feb/comb'),
    read_in('./months/mar/comb'),
    read_in('./months/apr/comb'),
    read_in('./months/may/comb'),
    read_in('./months/jun/comb'),
    read_in('./months/jul/comb'),
    read_in('./months/aug/comb'),
    read_in('./months/sep/comb'),
    read_in('./months/oct/comb'),
    read_in('./months/nov/comb'),
    read_in('./months/dec/comb')
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

def trace_posterior():
    li = read_in('./gaussian/trace_posterior')
    y = [float(v[0]) for v in li]

    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label='y', bins=100)
    pyplot.xlabel('$\Theta$')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/trace_posterior_hist.png')
    pyplot.figure()

    y = y[500:]
    pyplot.hist(y, alpha=0.5, label='y')
    pyplot.xlabel('$\Theta$ with burn in of 500 samples')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/trace_posterior_hist_burnin.png')
    pyplot.figure()


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
    pyplot.hist(y, alpha=0.5, label='y')
    pyplot.xlabel('$\Theta$')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/smc_posterior_hist.png')
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

combine_csv('./months/jan/', 'jan_5', 'jan_6', 'jan_3', 'jan_4')
combine_csv('./months/feb/', 'feb_5', 'feb_6', 'feb_3', 'feb_4')
combine_csv('./months/mar/', 'mar_5', 'mar_6', 'mar_3', 'mar_4')
combine_csv('./months/apr/', 'apr_5', 'apr_6', 'apr_3', 'apr_4')
combine_csv('./months/may/', 'may_5', 'may_6', 'may_3', 'may_4')
combine_csv('./months/jun/', 'jun_5', 'jun_6', 'jun_3', 'jun_4')
combine_csv('./months/jul/', 'jul_5', 'jul_6', 'jul_3', 'jul_4')
combine_csv('./months/aug/', 'aug_5', 'aug_6', 'aug_3', 'aug_4')
combine_csv('./months/sep/', 'sep_5', 'sep_6', 'sep_3', 'sep_4')
combine_csv('./months/oct/', 'oct_5', 'oct_6', 'oct_3', 'oct_4')
combine_csv('./months/nov/', 'nov_5', 'nov_6', 'nov_3', 'nov_4')
combine_csv('./months/dec/', 'dec_5', 'dec_6', 'dec_3', 'dec_4')


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


jan = process_month('./months/jan/comb', 'January'  , labels)
feb = process_month('./months/feb/comb', 'Feburary' , labels)
mar = process_month('./months/mar/comb', 'March'    , labels)
apr = process_month('./months/apr/comb', 'April'    , labels)
may = process_month('./months/may/comb', 'May'      , labels)
jun = process_month('./months/jun/comb', 'June'     , labels)
jul = process_month('./months/jul/comb', 'July'     , labels)
aug = process_month('./months/aug/comb', 'August'   , labels)
sep = process_month('./months/sep/comb', 'September', labels)
oct = process_month('./months/oct/comb', 'October'  , labels)
nov = process_month('./months/nov/comb', 'November' , labels)
dec = process_month('./months/dec/comb', 'December' , labels)


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

graph_vals("./", labels, calculate_global_temperature_change(), "Global", False)
