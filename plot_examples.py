
import matplotlib.pyplot as plt
import csv

f =  './output.csv'
data = csv.reader(open(f, 'rt'))
li = [tuple(row) for row in data]

x = [v[0] for v in li]
y = [v[1] for v in li]

plt.plot(y,x, 'ro')
plt.savefig('posterior.png')
