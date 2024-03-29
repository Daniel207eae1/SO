from multiprocessing import Pool, cpu_count
from PIL import Image, ImageFilter
import os
import time

input_dir = 'val2017/'
output_dir = 'dataset_procesado/'

def procesamiento(file):
    image = Image.open(input_dir + file)
    image = image.filter(ImageFilter.GaussianBlur(2))
    image = image.convert('L')
    image = image.convert('1')
    image = image.rotate(45, expand = True)
    
    image.save(output_dir + file)

if not os.path.exists(output_dir):
    os.mkdir(output_dir)
    
list_files = os.listdir(input_dir)

#secuencial
start = time.time()
for file in list_files:
    procesamiento(file)
print('Tiempo total serial: ', time.time()-start, '\n')

#multiprocesamiento

start = time.time()
p = Pool(cpu_count())
p.map(procesamiento, list_files)
p.close()
print('Tiempo total paralelo: ', time.time()-start, '\n')