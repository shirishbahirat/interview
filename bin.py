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
            lim.append(i)
            sum = -20000
    paral.append((1 - 1/p)**n)


n1 = 16*.2
n2 = 16*.4
n3 = 16*.1
n4 = 16*.3

p1 = 1 /(1 - 0.95**(1/n1))
p2 = 1 /(1 - 0.95**(1/n2))
p3 = 1 /(1 - 0.95**(1/n3))
p4 = 1 /(1 - 0.95**(1/n4))

sum = 0
for i in range(32):
    sum += binom.pmf(i, n1, 1/p1)
    if sum >= .999:
        print(i)
        sum = -20000


sum = 0
for i in range(32):
    sum += binom.pmf(i, n2, 1/p2)
    if sum >= .999:
        print(i)
        sum = -20000


sum = 0
for i in range(32):
    sum += binom.pmf(i, n3, 1/p3)
    if sum >= .999:
        print(i)
        sum = -20000


sum = 0
for i in range(32):
    sum += binom.pmf(i, n4, 1/p4)
    if sum >= .999:
        print(i)
        sum = -20000


print(p1, p2, p3, p4, p1+p2+p3+p4)

