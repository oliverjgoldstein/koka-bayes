import random
import numpy as np
from matplotlib import pyplot
import csv

def combine_csv(path, csv_1, csv_2):
    fout = open((path+"comb.csv"),"w+")
    for line in open(path+csv_1+'.csv'):
        fout.write(line)
    for line in open(path+csv_2+'.csv'):
        fout.write(line)


def process_month(path, month, labels):
    li = read_in(path)
    x1 = [float(v[0]) for v in li]
    y1 = [float(v[2])  for v in li]
    
    pyplot.figure()
    
    pyplot.plot(y1,x1, 'ro')
    pyplot.ylabel('Likelihood')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) :')
    pyplot.savefig(path + '_points.png')
    
    pyplot.figure()
        
    y2  = [float(v[3])  for v in li]
    y3  = [float(v[4])  for v in li]
    y4  = [float(v[5])  for v in li]
    y5  = [float(v[6])  for v in li]
    y6  = [float(v[7])  for v in li]
    y7  = [float(v[8])  for v in li]
    y8  = [float(v[9])  for v in li]
    y9  = [float(v[10]) for v in li]
    y10 = [float(v[11]) for v in li]
    y11 = [float(v[12]) for v in li]
    y12 = [float(v[13]) for v in li]
    y13 = [float(v[14]) for v in li]
    
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
    
    y_min = int(min(y_reduced))
    y_max = int(max(y_reduced))
    
    for val in range(0, len(ys)):
        pyplot.figure()
        
        pyplot.hist(ys[val], alpha=0.5, label='Temperature')
        pyplot.xlim(y_min, y_max)
        pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[val])
        pyplot.ylabel('Frequency')
        pyplot.legend(loc='upper right')
        pyplot.savefig(path + '_hist_'+str(val)+'.png')
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
    for time_period in range(2, 15):
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


def graph_vals(path, labels, month_vals, month_name):
    x_pos = np.arange(len(labels))
    means = [mean[0] for mean in month_vals]
    errors = [std[1] for std in month_vals]
    
    fig, ax = pyplot.subplots()
    ax.bar(
        x_pos, 
        means,
        yerr=errors,
        align='center',
        alpha=0.5,
        ecolor='black',
        capsize=10)
        
    ax.set_ylabel('Temperature ($^\circ$ C)')
    ax.set_xticks(x_pos)    
    ax.set_xticklabels(labels, rotation='vertical', fontsize=16)
    ax.set_title(month_name + ' temperature change over time.')
    ax.yaxis.grid(True)

    # Save the figure and show
    pyplot.tight_layout()
    pyplot.savefig(path+'aggregate.png')

def gaussian_posterior():
    li = read_in('./gaussian/gaussian_posterior')
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]
    
    pyplot.figure()
    pyplot.plot(y,x, 'ro')
    pyplot.ylabel('likelihood')
    pyplot.xlabel('$\theta$')
    pyplot.savefig('./gaussian/gaussian_posterior_points.png')
    pyplot.figure()
    pyplot.hist(y, alpha=0.5, label='y')
    pyplot.xlabel('$\theta$')
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig('./gaussian/gaussian_posterior_hist.png')
    pyplot.figure()

gaussian_posterior()

combine_csv('./months/jan/', 'jan_1', 'jan_2')
combine_csv('./months/feb/', 'feb_1', 'feb_2')
combine_csv('./months/mar/', 'mar_1', 'mar_2')
combine_csv('./months/apr/', 'apr_1', 'apr_2')
combine_csv('./months/may/', 'may_1', 'may_2')
combine_csv('./months/jun/', 'jun_1', 'jun_2')
combine_csv('./months/jul/', 'jul_1', 'jul_2')
combine_csv('./months/aug/', 'aug_1', 'aug_2')
combine_csv('./months/sep/', 'sep_1', 'sep_2')
combine_csv('./months/oct/', 'oct_1', 'oct_2')
combine_csv('./months/nov/', 'nov_1', 'nov_2')
combine_csv('./months/dec/', 'dec_1', 'dec_2')


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


graph_vals('./months/jan/', labels, jan, 'January'  )
graph_vals('./months/feb/', labels, feb, 'Feburary' )
graph_vals('./months/mar/', labels, mar, 'March'    )
graph_vals('./months/apr/', labels, apr, 'April'    )
graph_vals('./months/may/', labels, may, 'May'      )
graph_vals('./months/jun/', labels, jun, 'June'     )
graph_vals('./months/jul/', labels, jul, 'July'     )
graph_vals('./months/aug/', labels, aug, 'August'   )
graph_vals('./months/sep/', labels, sep, 'September')
graph_vals('./months/oct/', labels, oct, 'October'  )
graph_vals('./months/nov/', labels, nov, 'November' )
graph_vals('./months/dec/', labels, dec, 'December' )


graph_vals("./", labels, calculate_global_temperature_change(), "Global")

