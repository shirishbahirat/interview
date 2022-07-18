from scipy.stats import binom
import matplotlib.pyplot as plt

qd = n = 32
p = die = 1/128

lim = []
prob = []


for p in range(4, 256, 8):
    sum = 0
    prob = []
    for i in range(32):
        sum += binom.pmf(i, n, 1/p)
        prob.append(binom.pmf(i, n, 1/p))
        if sum >= .999:
            print (i)
            lim.append(i)
            sum = -20000


    plt.plot(prob)
plt.show()

plt.plot(lim)

plt.ylabel('QoS .999')

plt.xlabel('resources')

plt.show()
