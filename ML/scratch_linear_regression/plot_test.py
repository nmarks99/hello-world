import matplotlib.pyplot as plt
import numpy as np
import pandas as pd 

# Import the data
# (hours studied, test score)
points = np.genfromtxt('data.csv',delimiter=',') 
hrs = []
scores = []
for i in range(len(points)):
    hrs.append(points[i,0])
    scores.append(points[i,1])


b = 0.08893651993741346
m = 1.4777440851894448
y = []
for i in range(100):
    y.append(m*i + b)

fig,ax = plt.subplots(figsize=(10,7))
ax.scatter(hrs,scores)
ax.plot(y,'-r',label='Best fit line')
ax.set(xlabel='Hours studied',ylabel='Test Score')
ax.grid()
ax.legend()
plt.show()
