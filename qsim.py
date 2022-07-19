import simpy
from queue import Queue as q
import attr
from random import random, randrange
import matplotlib as mpl
import matplotlib.pyplot as plt
from scipy.stats import binom


@attr.s
class cmd(object):

    dmn = attr.ib(0)

    time = attr.ib(0)


 class model(object):

    def __init__(self, env, res, dmns, qd):

        self.env = env

        self.res = res

        self.dmns = dmns

        self.qd = qd

        self.rate = [4 for _ in range(dmns)]

        self.domains = sorted([i for in range (dmns)], key = lambda x: random())

        self.proc = [env.process(self.process(id)) for id in range(res)]

        self.disp = [env.process(self.dispatcher(id)) for id in range(dmns)]

        self.queu_res = [q() for _ in range(res)]

        self.n1 = {'time':[0 for _ in range(dmns)],
                  'cnt':[0 for _ in range(dmns)],
                  'data': [0 for _ in range(dmns)],
                  'thresh': 100 - 1, 
                  'meas': [0 for _ in range(dmns)]}

        self.n2 = {'time':[0 for _ in range(dmns)],
                  'cnt':[0 for _ in range(dmns)],
                  'data': [0 for _ in range(dmns)],
                  'thresh': 1000 - 1, 
                  'meas': [0 for _ in range(dmns)]}

        self.n3 = {'time':[0 for _ in range(dmns)],
                  'cnt':[0 for _ in range(dmns)],
                  'data': [0 for _ in range(dmns)],
                  'thresh': 10000 - 1, 
                  'meas': [0 for _ in range(dmns)]}

        self.n4 = {'time':[0 for _ in range(dmns)],
                  'cnt':[0 for _ in range(dmns)],
                  'data': [0 for _ in range(dmns)],
                  'thresh': 100000 - 1, 
                  'meas': [0 for _ in range(dmns)]}

        self.n5 = {'time':[0 for _ in range(dmns)],
                  'cnt':[0 for _ in range(dmns)],
                  'data': [0 for _ in range(dmns)],
                  'thresh': 1000000 - 1, 
                  'meas': [0 for _ in range(dmns)]}

    def qos(self, n, dmn, time):

        n['cnt'][dmn] += 1

        lat = self.env.now - time

        if lat > n['time'][dmn]:

            n['time'][dmn] = lat

        if n['cnt'][dmn] >= n['thresh']:

            n['data'][dmn] = int((n['data'][dmn] + n['time'][dmn])/2.0)

            n['cnt'][dmn] = 0;
            
            n['time'][dmn]  = 0;

            n['meas'][dmn] += 1

    def print_qos(self):

        print('.99', self.n1['data'], self.n1['meas'])

        print('.999', self.n2['data'], self.n2['meas'])

        print('.9999', self.n3['data'], self.n3['meas'])

        print('.99999', self.n4['data'], self.n4['meas'])

        print('.999999', self.n5['data'], self.n5['meas'])


    def dispatcher(self, id):

        while True:

            yield self.env.timeout(self.rate[id])

            cm = cmd(id, self.env.now)

            res_queue = randrange(0, self.dmns)

            self.queu_res[res_queue].put(cm)

            self.per_dmn_cmd_cnt[id] += 1

            err = self.qd[id] - self.per_dmn_cmd_cnt[id]

            self.rate[id] = self.rate[id] + 0.05*err


    def process(self, id):
        
        while True:

            yield self.env.timeout(self.exec)

            if self.queu_res[id].qsize():

                cm = self.queu_res[id].get()

                self.per_dmn_cmd_cnt[cm.dmn] -= 1

                self.qos(self.n1, cm.dmn, cm.time)

                self.qos(self.n2, cm.dmn, cm.time)

                self.qos(self.n3, cm.dmn, cm.time)

                self.qos(self.n4, cm.dmn, cm.time)

                self.qos(self.n5, cm.dmn, cm.time)


def main():

    env = simpy.Environment()

    rate = [2, 4, 5, 6, 7, 8, 9, 19, 20, 30]

    md = model(env, 128, 1, [28])

    env.run(5e5)

    md.print_qos()


if __name__ == "__main__":
    main()