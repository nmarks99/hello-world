from matplotlib import pyplot as plt 
import math
import numpy as np

x = np.arange(0,(2*math.pi),(math.pi/180))
y = [math.sin(i) for i in x]

fig,ax, = plt.subplots()
ax.plot(x,y)
plt.show() 