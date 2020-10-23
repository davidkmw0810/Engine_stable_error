import csv
import numpy as np
from matplotlib import pyplot as plt

# file get
normal = open('./normal.csv', 'r', encoding = 'utf-8')
error = open('./error.csv', 'r', encoding = 'utf-8')

data_nor = [[], [], []]
data_err = [[], [], []]

rd = csv.reader(normal)
for line in rd:
    data_nor[0].append(int(line[0])) # time
    data_nor[1].append(float(line[1])) # speed
    data_nor[2].append(float(line[2])) # acc

rd = csv.reader(error)
for line in rd:
    data_err[0].append(int(line[0])) # time
    data_err[1].append(float(line[1])) # speed
    data_err[2].append(float(line[2])) # acc

normal.close()
error.close()

# intention
nor = []

# intention per acc
nor_ipa = []

for i in range(0, len(data_nor) - 1):
    acc = data_nor[2][i]
    if acc == 0:
        nor.append()
        continue
    else:
        nor_inte = (data_nor[1][i+1] - data_nor[1][i])/acc
        nor_ipa.append(nor_inte/acc)
        nor.append(nor_inte)


# data_nor[3] = nor_inte, data_nor[4] = nor_ipa
data_nor.append(nor)
data_nor.append(nor_ipa)

# avg inte
nor_avg = sum(data_nor[4])/len(data_nor[4])
print(nor_avg)
## find average of intention per acc
## detect anomaly

count = 0

for i in range(0, len(data_err)-1):
    err_acc = data_err[1][i+1]-data_err[1][i] # real accle
    nor_intention = nor_avg*data_err[2][i] # calculate accle
    
    if(nor_intention != err_acc):
        count += 1
    
print("anomaly event : 50\nfound event : " + str(count))
