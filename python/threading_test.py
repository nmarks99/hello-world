import threading
import time 
import os

def func():
    print('ran')
    time.sleep(1)
    print('done')

# Define thread
x = threading.Thread(target=func)
x.start() # run the thread
print(threading.activeCount())

#  print("\x1B[0m")


