import threading
import time
import tui

def poll():
    ax = 1
    ay = 2
    az = 3
    amag = 4
    return ax, ay, az, amag


def func(arr,stop_thread):
    t0 = time.time()
    while True:

        elap = time.time() - t0
        ax, ay, az, amag = poll()
        arr.append([ax, ay, az, amag, elap])
        time.sleep(0.1)
        if stop_thread.is_set():
            break

# Define thread
stop_thread = threading.Event() 
arr = []
x = threading.Thread(target=func,args=(arr,stop_thread,))
x.start() # run the thread

try:
    print("Active threads = ",threading.active_count())
    while True:
        tui.clear()
        print("Running...")
        print(len(arr))
        time.sleep(1)
        

except KeyboardInterrupt:
   print("out = ",arr)
   stop_thread.set()
   x.join()
   print("Active threads = ",threading.active_count())

