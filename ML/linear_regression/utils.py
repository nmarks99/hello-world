import pandas as pd
import matplotlib.pyplot as plt 
import numpy as np


def load_data(filename):
    df = pd.read_csv(filename,sep=",",index_col=False)
    df.columns = ["Size","Rooms","Price"]
    data = np.array(df,dtype=float)
    normalize(data) 
    return data


def normalize(data):
    '''
    feature normalization:
    Z = (x - u)/sigma
    
    x: non-normalized feature
    u: mean
    sigma: standard deviation
    '''

    for i in range(0,data.shape[1]-1):
        data[:,i] = ((data[:,i] - np.mean(data[:,i]))/np.std(data[:,i]))


def plot_data(x,y):
    plt.style.use("ggplot")
    fig,ax = plt.subplots()
    ax.set(xlabel="House size",ylabel="Price")
    ax.plot(x[:,0],y,'bo')
    plt.show()

