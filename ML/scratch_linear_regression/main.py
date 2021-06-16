import numpy as np


def compute_error(b, m, points):
    # Initialize error at 0
    totalError = 0

    # For every point
    for i in range(0,len(points):
        # Get the x value
        x = points[i,0]
        # Get the y value
        y = points[0,i]

        # Get difference, square it, add it to total error
        totalError += (y - (m*x + b))**2

    return totalError / float(len(points))



def gradient_descent_runner():
    pass

def run():
    
    # Step 1 - Collect data
    points = np.genfromtxt('data.csv',delimiter=',') # (hours studied, test score)

    # Step 2 - Define hyperparameters
    # How fast should our model converge?
    learning_rate = 0.0001
    initial_b = 0 # y-intercept
    initial_m = 0 # Slope
    num_iterations = 1000 # note our data only has 100 data points

    # Step 3 - Train the model
    print('Starting gradient descent at b = {0},m = {1}, error = {2}'.format(initial_b,initial_m,compute_error(initial_b,initial_m)))
    [b, m] = gradient_descent_runner(points,initial_b,initial_m,learning_rate,num_iterations)
    print('Ending point at b = {1}, m = {2}, error = {3}'.format(num_iterations,b,compute_error(b,m,points)))


if __name__ == '__main__':
    run()