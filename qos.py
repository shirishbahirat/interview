from scipy.stats import binom
import matplotlib.pyplot as plt
from math import log



def get_qos(p1, n1):

	qos = [0, 0, 0, 0]

	sum = 0
	for i in range(64):
	    sum += binom.pmf(i, n1, 1/p1)
	    if sum >= .99 and qos[0] == 0:
	        qos[0] = i

	    if sum >= .999 and qos[1] == 0:
	        qos[1] = i

	    if sum >= .9999 and qos[2] == 0:
	        qos[2] = i

	    if sum >= .99999 and qos[3] == 0:
	        qos[3] = i

	print(qos, (1 - 1/p1)**n1, n1)


p1 = 128 #qd
n1 = 1/(log(1 - (1/p1), 0.8)) # die

get_qos(p1, n1)

p2 = 64 #qd
n2 = 1/(log(1 - (1/p2), 0.9)) # die

get_qos(p2, n2)

p3 = 32 #qd
n3 = 1/(log(1 - (1/p3), 0.95)) # die

get_qos(p3, n3)

p4 = 256 #qd
n4 = 1/(log(1 - (1/p4), 0.95)) # die

get_qos(p4, n4)
