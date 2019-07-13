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
    data = csv.reader(open(path + '.csv', 'rt'))
    li = [tuple(row) for row in data]
    li = li[:len(li)-1]
    x1 = [float(v[0]) for v in li]
    y1 = [float(v[2]) for v in li]
    
    pyplot.figure()
    
    pyplot.plot(y1,x1, 'ro')
    pyplot.ylabel('Likelihood')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) :')
    pyplot.savefig(path + '_points.png')
    
    pyplot.figure()
    
    pyplot.hist(y1, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[0])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_1.png')
    
    y2 = [float(v[3]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y2, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[1])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_2.png')
    
    y3 = [float(v[4]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y3, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[2])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_3.png')
    
    y4 = [float(v[5]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y4, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[3])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_4.png')
    
    y5 = [float(v[6]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y5, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[4])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_5.png')
    
    y6 = [float(v[7]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y6, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[5])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_6.png')
    
    
    y7 = [float(v[8]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y7, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[6])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_7.png')
    
    
    y8 = [float(v[9]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y8, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[7])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_8.png')
    
    
    y9 = [float(v[10]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y9, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[8])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_9.png')
    
    
    y10 = [float(v[11]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y10, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[9])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_10.png')
    
    
    y11 = [float(v[12]) for v in li]

    pyplot.figure()

    pyplot.hist(y11, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[10])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_11.png')



    y12 = [float(v[13]) for v in li]

    pyplot.figure()

    pyplot.hist(y12, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[11])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_12.png')


    y13 = [float(v[14]) for v in li]

    pyplot.figure()

    pyplot.hist(y13, alpha=0.5, label='y')
    pyplot.xlabel(month + ' temperature ($^\circ$ C) : ' + labels[12])
    pyplot.ylabel('Frequency')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_13.png')

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
    (np.mean(y13), np.std(y13)),
    ]


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


f =  './gaussian/gaussian_posterior'
data = csv.reader(open(f + '.csv', 'rt'))
li = [tuple(row) for row in data]
li = li[:len(li)-1]
x = [float(v[0]) for v in li]
y = [float(v[1]) for v in li]

pyplot.figure()

pyplot.plot(y,x, 'ro')
pyplot.ylabel('likelihood')
pyplot.xlabel('theta')
pyplot.savefig(f + '_points.png')

pyplot.figure()

pyplot.hist(y, alpha=0.5, label='y')
pyplot.xlabel('theta')
pyplot.ylabel('count')
pyplot.legend(loc='upper right')
pyplot.savefig(f + '_hist.png')


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


jan = process_month('./months/jan/comb', 'January'   , labels)       
feb = process_month('./months/feb/comb', 'Feburary'  , labels)           
mar = process_month('./months/mar/comb', 'March'     , labels)       
apr = process_month('./months/apr/comb', 'April'     , labels)       
may = process_month('./months/may/comb', 'May'       , labels)   
jun = process_month('./months/jun/comb', 'June'      , labels)       
jul = process_month('./months/jul/comb', 'July'      , labels)       
aug = process_month('./months/aug/comb', 'August'    , labels)       
sep = process_month('./months/sep/comb', 'September' , labels)           
oct = process_month('./months/oct/comb', 'October'   , labels)       
nov = process_month('./months/nov/comb', 'November'  , labels)           
dec = process_month('./months/dec/comb', 'December'  , labels)           


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


