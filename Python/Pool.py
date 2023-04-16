from multiprocessing import Pool

def cube(number):
    return number*number*number

numbers = range(100)

pool = Pool(10)

result = pool.map(cube, numbers)

pool.close()
pool.join()

print(result)