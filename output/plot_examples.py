import random
import numpy
from matplotlib import pyplot
import csv

f =  ['./gaussian_posterior', 'temperature_posterior']
for i in range(0, len(f)):
    data = csv.reader(open(f[i] + '.csv', 'rt'))
    li = [tuple(row) for row in data]
    li = li[:len(li)-1]
    x = [float(v[0]) for v in li]
    y = [float(v[1]) for v in li]
    print(sum(x))

    pyplot.figure()

    pyplot.plot(y,x, 'ro')
    pyplot.ylabel('likelihood')
    pyplot.xlabel('theta')
    pyplot.savefig(f[i] + '_points.png')

    pyplot.figure()

    pyplot.hist(y, alpha=0.5, label='y')
    pyplot.xlabel('theta')
    pyplot.ylabel('count')
    pyplot.legend(loc='upper right')
    pyplot.savefig(f[i] + '_hist.png')
