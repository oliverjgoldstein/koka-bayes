import random
from matplotlib import pyplot
import csv

def combine_csv(path, csv_1, csv_2):
    fout = open((path+"comb.csv"),"w+")
    for line in open(path+csv_1+'.csv'):
        fout.write(line)
    for line in open(path+csv_2+'.csv'):
        fout.write(line)


def process_month(path):
    data = csv.reader(open(path + '.csv', 'rt'))
    li = [tuple(row) for row in data]
    li = li[:len(li)-1]
    x1 = [float(v[0]) for v in li]
    y1 = [float(v[2]) for v in li]
    
    pyplot.figure()
    
    pyplot.plot(y1,x1, 'ro')
    pyplot.ylabel('likelihood')
    pyplot.xlabel('theta')
    pyplot.savefig(path + '_points.png')
    
    pyplot.figure()
    
    pyplot.hist(y1, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_1.png')
    
    y2 = [float(v[3]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y2, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_2.png')
    
    y3 = [float(v[4]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y3, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_3.png')
    
    y4 = [float(v[5]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y4, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_4.png')
    
    y5 = [float(v[6]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y5, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_5.png')
    
    y6 = [float(v[7]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y6, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_6.png')
    
    
    y7 = [float(v[8]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y7, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_7.png')
    
    
    y8 = [float(v[9]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y8, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_8.png')
    
    
    y9 = [float(v[10]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y9, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_9.png')
    
    
    y10 = [float(v[11]) for v in li]
    
    pyplot.figure()
    
    pyplot.hist(y10, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_10.png')
    
    
    y11 = [float(v[12]) for v in li]

    pyplot.figure()

    pyplot.hist(y11, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_11.png')



    y12 = [float(v[13]) for v in li]

    pyplot.figure()

    pyplot.hist(y12, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_12.png')


    y13 = [float(v[14]) for v in li]

    pyplot.figure()

    pyplot.hist(y13, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(path + '_hist_13.png')




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

process_month('./months/jan/comb')
process_month('./months/feb/comb')
process_month('./months/mar/comb')
process_month('./months/apr/comb')
process_month('./months/may/comb')
process_month('./months/jun/comb')
process_month('./months/jul/comb')
process_month('./months/aug/comb')
process_month('./months/sep/comb')
process_month('./months/oct/comb')
process_month('./months/nov/comb')
process_month('./months/dec/comb')
