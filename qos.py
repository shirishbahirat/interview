from scipy.stats import binom
import matplotlib.pyplot as plt
from math import log


p1 = 64 #qd
n1 = 1/(log(1 - (1/p1), 0.8)) # die

print((1 - 1/p1)**n1, n1)

qos = [0, 0, 0, 0]

sum = 0
for i in range(64):
    sum += binom.pmf(i, p1, 1/n1)
    if sum >= .9 and qos[0] == 0:
        qos[0] = i

    if sum >= .99 and qos[1] == 0:
        qos[1] = i

    if sum >= .999 and qos[2] == 0:
        qos[2] = i

    if sum >= .9999 and qos[3] == 0:
        qos[3] = i

print(qos)

