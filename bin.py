from scipy.stats import binom
import matplotlib.pyplot as plt

qd = n = 32
p = die = 1/128

lim = []
prob = []
paral = []


for p in range(8, 256, 8):
    sum = 0
    prob = []
    for i in range(32):
        sum += binom.pmf(i, n, 1/p)
        prob.append(binom.pmf(i, n, 1/p))
        if sum >= .999:
            print (i)
            lim.append(i)
            sum = -20000
    paral.append((1 - 1/p)**n)


t1 = 16
t2 = 64
t3 = 32
t4 = 48

p1 = -1 /(0.85**(1/t1) - 1)
p2 = -1 /(0.85**(1/t2) - 1)
p3 = -1 /(0.85**(1/t3) - 1)
p4 = -1 /(0.85**(1/t4) - 1)

print(p1, p2, p3, p4)

