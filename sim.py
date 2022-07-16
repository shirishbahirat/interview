import simpy
from queue import Queue as q
import attr
from random import random, randrange

@attr.s
class cmd(object):
    dmn = attr.ib(0)
    time = attr.ib(0)

class model(object):

    def __init__(self, env, res, cmds, dmns, rate):

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

        self.qd_per_domain = [32, 16, 8, 4]

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


    def optimizer(self):

        while True:

            yield self.env.timeout(60)

            print(self.measured_service_rate, self.per_dmn_cmd_cnt, self.res_per_dmn)

            for idx in range(self.domains):

                err = self.per_dmn_cmd_cnt[idx] - self.qd_per_domain[idx]

                dmns = max(1, self.res_per_dmn[idx] + 0.05*err*self.rate[idx])

                if dmns >= self.res:

                    dmns = self.res - 1

                self.res_per_dmn[idx] = int(dmns)

def main():

    env = simpy.Environment()

    rate = [5, 3, 2, 1]

    md = model(env, 256, 1024, 4, rate)

    env.run(100000)

if __name__ == "__main__":
    main()