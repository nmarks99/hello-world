from helpers import *

# Step 1 - Collect data
points = np.genfromtxt('data.csv',delimiter=',') # (hours studied, test score)

# Step 2 - Define hyperparameters
# How fast should our model converge?
learningRate = 0.0001
initial_b = 0 # y-intercept
initial_m = 0 # Slope
num_iterations = 1000 # note our data only has 100 data points

# Step 3 - Train the model
print('\nStarting gradient descent at b = {0},m = {1}, error = {2}'.format(initial_b,initial_m,compute_error(initial_b,initial_m,points)))
(b, m) = gradient_descent_runner(points,initial_b,initial_m,learningRate,num_iterations)
print('After {0} iterations b = {1}, m = {2}, error = {3}\n'.format(num_iterations,b,m,compute_error(b,m,points)))

# Plot the result
make_plot(points,b,m)