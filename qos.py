from scipy.stats import binom
import matplotlib.pyplot as plt
from math import log

def get_qos(p1, n1):

	qos = [0, 0, 0, 0]

	sum = 0
	for i in range(64):
	    sum += binom.pmf(i, p1, 1/n1)
	    if sum >= .99 and qos[0] == 0:
	        qos[0] = i*10

	    if sum >= .999 and qos[1] == 0:
	        qos[1] = i*10

	    if sum >= .9999 and qos[2] == 0:
	        qos[2] = i*10

	    if sum >= .99999 and qos[3] == 0:
	        qos[3] = i*10

	#print(qos, (1 - 1/p1)**n1, n1)

	return qos[0]


p1 = 128 #qd
n1 = 1/(log(1 - (1/p1), 0.8)) # die

get_qos(p1, n1)

p2 = 64 #qd
n2 = 1/(log(1 - (1/p2), 0.9)) # die

get_qos(p2, n2)

p3 = 32 #qd
n3 = 1/(log(1 - (1/p3), 0.95)) # die

get_qos(p3, n3)

p4 = 32 #qd
n4 = 1/(log(1 - (1/p4), 0.95)) # die

get_qos(p4, n4)

#plt.figure()

for j in range(4,512,32):
	qo = []
	res = []
	for i in range(1,10):
		n1 = 1/(log(1 - (1/p1), i/10 - 0.01))
		idx = get_qos(j, n1)
		qo.append(idx)
		res.append(int(n1))
		#plt.plot(res, qo)

#plt.show()



dmsn = 5

res_cnt = [2 for _ in range(dmsn)]

util = [1/dmsn for _ in range(dmsn)]

weight = [4, 3, 2, 1, 7]

s = sum(weight)

nwt = [weight[i]/s for i in range(dmsn)]



run = True

import time

cnt = 0

while run:

	time.sleep(.01)

	if cnt > 1000:
		run = False
	
	cnt += 1

	print(cnt)





