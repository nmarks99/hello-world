import pandas as pd 
import numpy as np
import sklearn
from sklearn import linear_model

dataPath = r"C:\Users\nmark\Documents\GitHub\hello-world\ML_linear_regression\data\student-mat.csv"
data = pd.read_csv(dataPath,sep=';')

print(data.head())

data = data[["G1","G2","G3","studytime","failures","absences"]]

predict = "G3" # Predict final grade

X = np.array(data.drop(["G3"],1))   # New data frame without G3
Y = np.array(data[predict]) # Just the G3 value


