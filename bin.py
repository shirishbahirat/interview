from scipy.stats import binom

qd = n = 64
p = die = 1/16

sum = 0
for i in range(200):
    sum += binom.pmf(i, n, p)
    if sum >= .999:
        print (i)

