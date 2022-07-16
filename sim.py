import simpy
from queue import Queue as q

class model(object):

	def __init__(self, env, res, cmds):
		self.env = env
		self.proc = [env.process(self.process(id)) for id in range(res)]


	def process(self, id):
		
		while True:
			yield self.env.timeout(10)
			print('hehe', id, self.env.now)



def main():

	env = simpy.Environment()

	md = model(env, 256, 1024)

	env.run(1000)

if __name__ == "__main__":
    main()