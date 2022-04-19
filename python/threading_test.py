import threading
import time 

def func():
    print('ran')
    time.sleep(1)
    print('done')

# Define thread
x = threading.Thread(target=func)
x.start() # run the thread
print(threading.activeCount())

