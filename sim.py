import simpy
from queue import Queue as q
import attr
from random import random, randrange
import matplotlib as mpl
import matplotlib.pyplot as plt

@attr.s
class cmd(object):
    dmn = attr.ib(0)
    time = attr.ib(0)

class model(object):

    def __init__(self, env, res, dmns, rate):

        self.mu = 0.05

        self.env = env

        self.rate = rate

        self.res = res

        self.domains = dmns

        self.proc = [env.process(self.process(id)) for id in range(res)]

        self.disp = [env.process(self.dispatcher(id)) for id in range(dmns)]

        self.opti = env.process(self.optimizer())

        self.queu_res = [q() for _ in range(res)]

        self.exec = 10

        self.measured_service_rate = [0 for _ in range(dmns)]

        self.res_per_dmn = [1 for _ in range(dmns)]

        self.pick = sorted([i for i in range(res)], key = lambda x: random())

        self.per_dmn_cmd_cnt = [0 for _ in range(dmns)]

        self.qd_per_domain = [4 for _ in range(self.domains)]

        self.n1_target = [3*10*(i+1) for i in range(self.domains)]

        self.n2_target = [4*10*(i+1) for i in range(self.domains)]

        self.n3_target = [5*10*(i+1) for i in range(self.domains)]

        self.n4_target = [6*10*(i+1) for i in range(self.domains)]

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

        self.err_trace = [[] for _ in range(self.domains)]

        self.res_trace = [[] for _ in range(self.domains)]

        self.qos_trace = [[] for _ in range(self.domains)]

        self.qos_error = [[] for _ in range(self.domains)]

        self.bw_error = [[] for _ in range(self.domains)]


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

    def print_per_dmn_res(self):

        print('res per dmn', self.res_per_dmn)

    def dispatcher(self, id):

        while True:

            yield self.env.timeout(self.rate[id])

            cm = cmd(id, self.env.now)

            res_queue = randrange(0, self.res_per_dmn[id])

            self.queu_res[self.pick[res_queue]].put(cm)

            self.per_dmn_cmd_cnt[id] += 1


    def process(self, id):
        
        while True:

            yield self.env.timeout(self.exec)

            if self.queu_res[id].qsize():

                cm = self.queu_res[id].get()

                self.measured_service_rate[cm.dmn] += 1

                self.per_dmn_cmd_cnt[cm.dmn] -= 1

                self.qos(self.n1, cm.dmn, cm.time)

                self.qos(self.n2, cm.dmn, cm.time)

                self.qos(self.n3, cm.dmn, cm.time)

                self.qos(self.n4, cm.dmn, cm.time)

                self.qos(self.n5, cm.dmn, cm.time)


    def optimizer(self):

        n1 = [32 for _ in range(self.domains)]
        n2 = [32 for _ in range(self.domains)]
        n3 = [32 for _ in range(self.domains)]
        n4 = [32 for _ in range(self.domains)]

        while True:

            yield self.env.timeout(60)

            for idx in range(self.domains):

                err1 = self.per_dmn_cmd_cnt[idx] - self.qd_per_domain[idx]

                if self.n1['meas'][idx] > n1[idx]:
                    err2 = self.n1['data'][idx] - self.n1_target[idx]
                    n1[idx] = self.n1['meas'][idx]

                    self.qos_trace[idx].append(self.n1['data'][idx])
                else:
                    err2 = 0

                if self.n2['meas'][idx] > n2[idx]:
                    err3 = self.n2['data'][idx] - self.n2_target[idx]
                    n2[idx] = self.n2['meas'][idx]
                else:
                    err3 = 0

                if self.n3['meas'][idx] > n3[idx]:
                    err4 = self.n3['data'][idx] - self.n3_target[idx]
                    n3[idx] = self.n3['meas'][idx]
                else:
                    err4 = 0

                err = err1 + err2*0.25 + err3*0.25 + err4*0.25

                self.err_trace[idx].append(err)

                dmns = max(1, self.res_per_dmn[idx] + self.mu*err*self.rate[idx])

                if dmns >= self.res:

                    dmns = self.res - 1

                self.res_per_dmn[idx] = int(dmns)

                self.res_trace[idx].append(int(dmns))

                self.qos_error[idx].append(int(err1))

                self.bw_error[idx].append(int(err - err1))


    def plot_data(self):

        plt.figure()
        plt.title('Combined Error')

        for i in range(self.domains):
            plt.plot(self.err_trace[i])
        plt.xlabel('time')

        plt.figure()
        plt.title('Resources')

        for i in range(self.domains):
            plt.plot(self.res_trace[i])
        plt.xlabel('time')

        plt.figure()
        plt.title('QoS')

        for i in range(self.domains):
            plt.plot(self.qos_trace[i])
        plt.xlabel('time')

        plt.figure()
        plt.title('QoS Error')

        for i in range(self.domains):
            plt.plot(self.qos_error[i])
        plt.xlabel('time')

        plt.figure()
        plt.title('BW Error')

        for i in range(self.domains):
            plt.plot(self.bw_error[i])
        plt.xlabel('time')

        plt.show()
   


def main():

    env = simpy.Environment()

    rate = [3, 4, 5, 6, 7, 8, 9, 19, 20, 30]

    md = model(env, 128, 6, rate)

    env.run(5e5)

    md.print_qos()

    md.print_per_dmn_res()

    md.plot_data()

if __name__ == "__main__":
    main()