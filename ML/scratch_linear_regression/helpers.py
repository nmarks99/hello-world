import numpy as np
import matplotlib.pyplot as plt
import pandas as pd 

def compute_error(b, m, points):
    # Initialize error at 0
    totalError = 0
    # For every point
    for i in range(0,len(points)):
        # Get the x value
        x = points[i,0]
        # Get the y value
        y = points[i,1]

        # Get difference, square it, add it to total error
        totalError += (y - (m*x + b))**2

    # Return the averge
    return totalError / float(len(points))


def step_gradient(b_current,m_current,points,learningRate):
    
    b_gradient = 0
    m_gradient = 0

    N = float(len(points))

    for i in range(0, len(points)):
        x = points[i,0]
        y = points[i,1]
        # Direction with respect to b and m
        # Computing partial derivatives of our error function
        b_gradient += -(2/N) * (y - ((m_current * x) + b_current))
        m_gradient += -(2/N) * x * (y - ((m_current * x) + b_current))

    # Update b and m values using our partial derivatives
    new_b = b_current - (learningRate * b_gradient)
    new_m = m_current - (learningRate * m_gradient)

    return (new_b,new_m)


def gradient_descent_runner(points,starting_b,starting_m,learningRate,num_iterations):
    # Starting b and m values
    b = starting_b
    m = starting_m

    # Gradient descent
    for i in range(num_iterations):
        # update b and m with new more accurate b and m by performing this gradient step
        (b, m) = step_gradient(b, m, np.array(points),learningRate)
    
    return (b,m)


