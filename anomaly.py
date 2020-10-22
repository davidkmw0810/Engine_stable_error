import csv
import numpy as np
from matplotlib import pyplot as plt

normal = open('./normal.csv', 'r', encoding = 'utf-8')
error = open('./error.csv', 'r', encoding = 'utf-8')

data_nor = [[], []]
data_err = [[], []]

rd = csv.reader(normal)
for line in rd:
    data_nor[0].append(line[0]) # time
    data_nor[1].append(line[1]) # speed

rd = csv.reader(error)
for line in rd:
    data_err[0].append(line[0]) # time
    data_err[1].append(line[1]) # speed

plt.scatter(data_err[0][0:50], data_err[1][0:50])
plt.title("Time / speed")
plt.xlabel("Time")
plt.ylabel("Speed")
#plt.axis([0,420,0,50])
plt.show()

