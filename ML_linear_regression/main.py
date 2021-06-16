import pandas as pd 
import numpy as np
import sklearn
from sklearn import linear_model
from matplotlib import pyplot as plt
import pickle

dataPath = r"data\student-mat.csv"
data = pd.read_csv(dataPath,sep=';')
data = data[["G1","G2","G3","studytime","failures","absences"]]
predict = "G3" # Predict final grade

X = np.array(data.drop(["G3"],1))   # New data frame without G3
Y = np.array(data[predict])         # Just the G3 value

x_train, x_test, y_train, y_test = sklearn.model_selection.train_test_split(X,Y,test_size = 0.1)

# Training 
linear = linear_model.LinearRegression()
linear.fit(x_train,y_train)
acc = linear.score(x_test,y_test)
print(acc)

# Save trained model as pickle
with open("studentmodel.pickle","wb") as f:
    pickle.dump(linear,f)

pickle_in = open("studentmodel.pickle","rb")
linear = pickle.load(pickle_in)

print("Co: ", linear.coef_)
print("Intercept: \n", linear.intercept_)

predictions = linear.predict(x_test)

for i in range(len(predictions)):
    print(predictions[i],x_test[i],y_test[i])