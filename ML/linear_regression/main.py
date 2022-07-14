#!/usr/bin/env python3
from utils import *

def main():
    data = load_data("house_price_data.txt")
    data_x = data[:,:2]
    data_y = data[:,-1]
    plot_data(data_x,data_y)


if __name__ == "__main__":
    main()

