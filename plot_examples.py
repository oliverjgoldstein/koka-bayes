import random
import numpy
from matplotlib import pyplot
import csv

f =  './output.csv'
data = csv.reader(open(f, 'rt'))
li = [tuple(row) for row in data]
li = li[:len(li)-1]
x = [float(v[0]) for v in li]
y = [float(v[1]) for v in li]
print(sum(x))

pyplot.plot(y,x, 'ro')
pyplot.savefig('posterior.png')
pyplot.figure()

bins = numpy.linspace(0.9, 1.1, 20)

# pyplot.hist(x, bins, alpha=0.5, label='x')
pyplot.hist(y, alpha=0.5, label='y')
pyplot.legend(loc='upper right')
pyplot.savefig('posterior_hist.png')
