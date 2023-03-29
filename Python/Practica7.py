from multiprocessing import Queue, Process
import time

def cube(numbers, queue):
    for i in numbers:
        queue.put(i*i*i)


def addone(numbers, queue):
    for i in numbers:
        queue.put(i+1)

q = Queue()
numbers = range(1, 5)        

#Ejecucion con multiproceso
start = time.time()
p1 = Process(target=cube, args=(numbers, q))
p2 = Process(target=addone, args=(numbers, q))

p1.start()
p2.start()

p1.join()
p2.join()

print('Tiempo de ejecucion paralelo', time.time()-start)

while not q.empty():
    print(q.get())