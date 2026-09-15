import random
import numpy as np
from matplotlib import pyplot
import csv
import scipy.stats as stats
import math
import matplotlib.cm as cm

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

def combine_csv_t(path, csv, csv_1, csv_2, csv_3, csv_4, csv_5):
    fout = open((path+csv+'.csv'),"w+")
    for line in open(path+csv_1+'.csv'):
        fout.write(line)
    for line in open(path+csv_2+'.csv'):
        fout.write(line)
    for line in open(path+csv_3+'.csv'):
        fout.write(line)
    for line in open(path+csv_4+'.csv'):
        fout.write(line)
    for line in open(path+csv_5+'.csv'):
        fout.write(line)



def process_month(path, month, labels, ylim):
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

    plot_hist(ys, month, path, labels, ylim)

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

    # pyplot.ylim(0,4200)
    # pyplot.xlim(y_min, y_max)
    # pyplot.xlabel(month + ' temperature ($^\circ$ C)')
    # pyplot.ylabel('Frequency')
    # pyplot.tight_layout(rect=[0,0,0.75,1])
    #
    # cols = ['red','red','red','red','red','red','red','blue','blue','blue','blue','blue','blue','blue']
    #
    # for val in range(0, len(ys)):
    #     pyplot.hist(ys[val], alpha=0.2, label=labels[val], color=cols[val])
    # pyplot.legend(bbox_to_anchor=(1.04,1), loc='upper left')
    # pyplot.subplots_adjust(right=0.7)
    # pyplot.savefig(path + '_hist_comb.png', bbox_inches="tight")
    # pyplot.figure()


    cols = ['blue','blue','blue','blue','blue','blue','blue','red','red','red','red','red','red','red']
    # cols = cm.rainbow(np.linspace(0, 1, len(ys)))
    for val in range(0, len(ys)):
        mu      = np.mean(ys[val])
        sigma   = np.std(ys[val])
        x       = np.linspace(mu - 3*sigma, mu + 3*sigma, 100)
        pyplot.plot(x, stats.norm.pdf(x, mu, sigma), label=labels[val], color=cols[val])

    pyplot.xlabel(month + ' temperature ($^\circ$ C)')
    pyplot.ylabel('Density')
    pyplot.tight_layout(rect=[0,0,0.75,1])
    pyplot.legend(bbox_to_anchor=(1.04,1), loc='upper left')
    pyplot.subplots_adjust(right=0.7)
    pyplot.savefig(path + '_hist_combined.png', bbox_inches="tight")
    pyplot.figure()

def plot_hist(ys, month, path, labels, ylim):

    y_reduced = reduce(list.__add__, ys)

    y_min = int(min(y_reduced) - 1.0)
    y_max = int(max(y_reduced) + 1.0)

    for val in range(0, len(ys)):
        pyplot.figure()
        pyplot.ylim(0,ylim)
        pyplot.hist(ys[val], alpha=0.5, label='Land temperature')
        pyplot.xlim(y_min, y_max)
        pyplot.tick_params(labelsize=20)
        pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[val], fontsize=20)
        pyplot.ylabel('Frequency', fontsize=20)
        pyplot.legend(loc='upper right')
        pyplot.savefig(path + '_hist_'+str(val+1)+'.png', bbox_inches = "tight")
        pyplot.tight_layout()
        pyplot.figure()

def calculate_global_temperature_change(extra):

    months = [
    read_in('./output-climate/jan/'+extra),
    read_in('./output-climate/feb/'+extra),
    read_in('./output-climate/mar/'+extra),
    read_in('./output-climate/apr/'+extra),
    read_in('./output-climate/may/'+extra),
    read_in('./output-climate/jun/'+extra),
    read_in('./output-climate/jul/'+extra),
    read_in('./output-climate/aug/'+extra),
    read_in('./output-climate/sep/'+extra),
    read_in('./output-climate/oct/'+extra),
    read_in('./output-climate/nov/'+extra),
    read_in('./output-climate/dec/'+extra)
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

    ax.set_ylabel('Land Temperature ($^\circ$ C)', fontsize=20)
    ax.set_xticks(x_pos)
    ax.set_xticklabels(labels, rotation='vertical', fontsize=20)
    ax.tick_params(labelsize=20)
    ax.set_title(month_name + ' land temperature change over time.', fontsize=16)
    ax.yaxis.grid(True)

    # Save the figure and show
    pyplot.tight_layout()
    pyplot.savefig(path+'aggregate.png', bbox_inches="tight")

def trace_posterior():
    li = read_in('./gaussian/trace_posterior')
    y = [float(v[0]) for v in li]

    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label='samples from the posterior', bins=100)
    pyplot.tick_params(labelsize=20)
    pyplot.xlabel('$\Theta$', fontsize=20)
    pyplot.ylabel('Frequency', fontsize=20)
    pyplot.legend(loc='upper right')
    pyplot.xlim(2.0, 4.0)
    pyplot.savefig('./gaussian/trace_posterior_hist.png', bbox_inches="tight")
    pyplot.figure()

    y = y[500:]
    pyplot.hist(y, alpha=0.5, label='samples from the posterior')
    pyplot.xlabel('$\Theta$ with burn in of 500 samples', fontsize=20)
    pyplot.ylabel('Frequency', fontsize=20)
    pyplot.tick_params(labelsize=20)
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/trace_posterior_hist_burnin.png', bbox_inches="tight")
    pyplot.figure()

def smc_posterior():

    li = read_in('./gaussian/rmsmc_posterior')
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]

    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label=' samples\n from\n the RMSMC\n posterior')

    li = read_in('./gaussian/smc_posterior')
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]
    # pyplot.plot(y,x, 'ro')
    # pyplot.ylabel('likelihood')
    # pyplot.xlabel('$\Theta$')
    # pyplot.savefig('./gaussian/smc_posterior_points.png')
    # pyplot.figure()
    pyplot.hist(y, alpha=0.5, label=' samples\n from\n the SMC\n posterior')
    pyplot.xlabel('$\Theta$', fontsize=20)
    pyplot.ylabel('Frequency', fontsize=20)
    pyplot.tick_params(labelsize=20)
    pyplot.xlim(2.0, 4.0)
    # pyplot.legend(loc='upper right')
    pyplot.tight_layout(rect=[0,0,0.75,1])
    pyplot.legend(bbox_to_anchor=(1.04,1), loc='upper left', prop={'size': 20})
    pyplot.subplots_adjust(right=0.7)
    pyplot.savefig('./gaussian/smc_posterior_hist.png', bbox_inches="tight")
    pyplot.figure()

def is_posterior():
    li = read_in('./gaussian/importance_sampling')
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]

    pyplot.figure()
    pyplot.plot(y,x, 'ro', label='samples from the posterior')
    pyplot.ylabel('probability', fontsize=20)
    pyplot.legend(loc='upper left')
    pyplot.xlabel('$\Theta$', fontsize=20)
    pyplot.tick_params(labelsize=20)
    pyplot.savefig('./gaussian/is_posterior_points.png', bbox_inches="tight")
    pyplot.figure()
    pyplot.tick_params(labelsize=20)
    pyplot.hist(y, alpha=0.5, label='samples from the prior')
    pyplot.xlabel('$\Theta$', fontsize=20)
    pyplot.ylabel('Frequency', fontsize=20)
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/is_posterior_hist.png', bbox_inches="tight")
    pyplot.figure()

def rmsmc_posterior():
    li = read_in('./gaussian/rmsmc_posterior')
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]

    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label='samples from the posterior')
    pyplot.xlabel('$\Theta$',  fontsize=20)
    pyplot.ylabel('Frequency', fontsize=20)
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/rmsmc_posterior_hist.png', bbox_inches="tight")
    pyplot.figure()

def add_together(list1, list2):
    list_build = []
    for i in range(0, len(list1)):
        list_build += [(np.mean([list1[i][0], list2[i][0]]), np.std([list1[i][0], list2[i][0]]))]
    return list_build

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

# rmsmc_posterior()
# smc_posterior()
# trace_posterior()
# is_posterior()


combine_csv('./output-climate/jan/', 'smc_results', 'jan_smc_1', 'jan_smc_2', 'jan_smc_3', 'jan_smc_4')
combine_csv('./output-climate/feb/', 'smc_results', 'feb_smc_1', 'feb_smc_2', 'feb_smc_3', 'feb_smc_4')
combine_csv('./output-climate/mar/', 'smc_results', 'mar_smc_1', 'mar_smc_2', 'mar_smc_3', 'mar_smc_4')
combine_csv('./output-climate/apr/', 'smc_results', 'apr_smc_1', 'apr_smc_2', 'apr_smc_3', 'apr_smc_4')
combine_csv('./output-climate/may/', 'smc_results', 'may_smc_1', 'may_smc_2', 'may_smc_3', 'may_smc_4')
combine_csv('./output-climate/jun/', 'smc_results', 'jun_smc_1', 'jun_smc_2', 'jun_smc_3', 'jun_smc_4')
combine_csv('./output-climate/jul/', 'smc_results', 'jul_smc_1', 'jul_smc_2', 'jul_smc_3', 'jul_smc_4')
combine_csv('./output-climate/aug/', 'smc_results', 'aug_smc_1', 'aug_smc_2', 'aug_smc_3', 'aug_smc_4')
combine_csv('./output-climate/sep/', 'smc_results', 'sep_smc_1', 'sep_smc_2', 'sep_smc_3', 'sep_smc_4')
combine_csv('./output-climate/oct/', 'smc_results', 'oct_smc_1', 'oct_smc_2', 'oct_smc_3', 'oct_smc_4')
combine_csv('./output-climate/nov/', 'smc_results', 'nov_smc_1', 'nov_smc_2', 'nov_smc_3', 'nov_smc_4')
combine_csv('./output-climate/dec/', 'smc_results', 'dec_smc_1', 'dec_smc_2', 'dec_smc_3', 'dec_smc_4')

combine_csv('./output-climate/jan/', 'smc_exp_two_results', 'jan_smc_5', 'jan_smc_6', 'jan_smc_7', 'jan_smc_8')
combine_csv('./output-climate/feb/', 'smc_exp_two_results', 'feb_smc_5', 'feb_smc_6', 'feb_smc_7', 'feb_smc_8')
combine_csv('./output-climate/mar/', 'smc_exp_two_results', 'mar_smc_5', 'mar_smc_6', 'mar_smc_7', 'mar_smc_8')
combine_csv('./output-climate/apr/', 'smc_exp_two_results', 'apr_smc_5', 'apr_smc_6', 'apr_smc_7', 'apr_smc_8')
combine_csv('./output-climate/may/', 'smc_exp_two_results', 'may_smc_5', 'may_smc_6', 'may_smc_7', 'may_smc_8')
combine_csv('./output-climate/jun/', 'smc_exp_two_results', 'jun_smc_5', 'jun_smc_6', 'jun_smc_7', 'jun_smc_8')
combine_csv('./output-climate/jul/', 'smc_exp_two_results', 'jul_smc_5', 'jul_smc_6', 'jul_smc_7', 'jul_smc_8')
combine_csv('./output-climate/aug/', 'smc_exp_two_results', 'aug_smc_5', 'aug_smc_6', 'aug_smc_7', 'aug_smc_8')
combine_csv('./output-climate/sep/', 'smc_exp_two_results', 'sep_smc_5', 'sep_smc_6', 'sep_smc_7', 'sep_smc_8')
combine_csv('./output-climate/oct/', 'smc_exp_two_results', 'oct_smc_5', 'oct_smc_6', 'oct_smc_7', 'oct_smc_8')
combine_csv('./output-climate/nov/', 'smc_exp_two_results', 'nov_smc_5', 'nov_smc_6', 'nov_smc_7', 'nov_smc_8')
combine_csv('./output-climate/dec/', 'smc_exp_two_results', 'dec_smc_5', 'dec_smc_6', 'dec_smc_7', 'dec_smc_8')

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


jan = process_month('./output-climate/jan/smc_results', 'January'  , labels, 4200)
feb = process_month('./output-climate/feb/smc_results', 'Feburary' , labels, 4200)
mar = process_month('./output-climate/mar/smc_results', 'March'    , labels, 4200)
apr = process_month('./output-climate/apr/smc_results', 'April'    , labels, 4200)
may = process_month('./output-climate/may/smc_results', 'May'      , labels, 4200)
jun = process_month('./output-climate/jun/smc_results', 'June'     , labels, 4200)
jul = process_month('./output-climate/jul/smc_results', 'July'     , labels, 4200)
aug = process_month('./output-climate/aug/smc_results', 'August'   , labels, 4200)
sep = process_month('./output-climate/sep/smc_results', 'September', labels, 4200)
oct = process_month('./output-climate/oct/smc_results', 'October'  , labels, 4200)
nov = process_month('./output-climate/nov/smc_results', 'November' , labels, 4200)
dec = process_month('./output-climate/dec/smc_results', 'December' , labels, 4200)


graph_vals('./output-climate/jan/jan_smc_', labels, jan, 'January'  , True)
graph_vals('./output-climate/feb/feb_smc_', labels, feb, 'Feburary' , True)
graph_vals('./output-climate/mar/mar_smc_', labels, mar, 'March'    , True)
graph_vals('./output-climate/apr/apr_smc_', labels, apr, 'April'    , True)
graph_vals('./output-climate/may/may_smc_', labels, may, 'May'      , True)
graph_vals('./output-climate/jun/jun_smc_', labels, jun, 'June'     , True)
graph_vals('./output-climate/jul/jul_smc_', labels, jul, 'July'     , True)
graph_vals('./output-climate/aug/aug_smc_', labels, aug, 'August'   , True)
graph_vals('./output-climate/sep/sep_smc_', labels, sep, 'September', True)
graph_vals('./output-climate/oct/oct_smc_', labels, oct, 'October'  , True)
graph_vals('./output-climate/nov/nov_smc_', labels, nov, 'November' , True)
graph_vals('./output-climate/dec/dec_smc_', labels, dec, 'December' , True)

vals_smc = calculate_global_temperature_change("smc_results")
vals_smc2 = calculate_global_temperature_change("smc_exp_two_results")
smc_added = add_together(vals_smc, vals_smc2)
graph_vals("./smc_", labels, smc_added, "Global", True)

jan = process_month('./output-climate/jan/tmcmc_results', 'January'  , labels, 20000)
feb = process_month('./output-climate/feb/tmcmc_results', 'Feburary' , labels, 20000)
mar = process_month('./output-climate/mar/tmcmc_results', 'March'    , labels, 20000)
apr = process_month('./output-climate/apr/tmcmc_results', 'April'    , labels, 20000)
may = process_month('./output-climate/may/tmcmc_results', 'May'      , labels, 20000)
jun = process_month('./output-climate/jun/tmcmc_results', 'June'     , labels, 20000)
jul = process_month('./output-climate/jul/tmcmc_results', 'July'     , labels, 20000)
aug = process_month('./output-climate/aug/tmcmc_results', 'August'   , labels, 20000)
sep = process_month('./output-climate/sep/tmcmc_results', 'September', labels, 20000)
oct = process_month('./output-climate/oct/tmcmc_results', 'October'  , labels, 20000)
nov = process_month('./output-climate/nov/tmcmc_results', 'November' , labels, 20000)
dec = process_month('./output-climate/dec/tmcmc_results', 'December' , labels, 20000)

graph_vals('./output-climate/jan/jan_tmcmc_', labels, jan, 'January'  , True)
graph_vals('./output-climate/feb/feb_tmcmc_', labels, feb, 'Feburary' , True)
graph_vals('./output-climate/mar/mar_tmcmc_', labels, mar, 'March'    , True)
graph_vals('./output-climate/apr/apr_tmcmc_', labels, apr, 'April'    , True)
graph_vals('./output-climate/may/may_tmcmc_', labels, may, 'May'      , True)
graph_vals('./output-climate/jun/jun_tmcmc_', labels, jun, 'June'     , True)
graph_vals('./output-climate/jul/jul_tmcmc_', labels, jul, 'July'     , True)
graph_vals('./output-climate/aug/aug_tmcmc_', labels, aug, 'August'   , True)
graph_vals('./output-climate/sep/sep_tmcmc_', labels, sep, 'September', True)
graph_vals('./output-climate/oct/oct_tmcmc_', labels, oct, 'October'  , True)
graph_vals('./output-climate/nov/nov_tmcmc_', labels, nov, 'November' , True)
graph_vals('./output-climate/dec/dec_tmcmc_', labels, dec, 'December' , True)

vals_tmcmc = calculate_global_temperature_change("tmcmc_results")
vals_tmcmc2 = calculate_global_temperature_change("tmcmc_exp_two_results")
tmcmc_added = add_together(vals_tmcmc, vals_tmcmc2)
graph_vals("./tmcmc_", labels, vals_tmcmc2, "Global", True)
