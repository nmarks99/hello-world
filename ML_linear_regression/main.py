import pandas as pd 
import numpy as np
import sklearn
from sklearn import linear_model
from matplotlib import pyplot as plt
from matplotlib import style 
import pickle
import os

dataPath = r"data\student-mat.csv"
data = pd.read_csv(dataPath,sep=';')
data = data[["G1","G2","G3","studytime","failures","absences"]]
predict = "G3" # Predict final grade

X = np.array(data.drop(["G3"],1))   # New data frame without G3
Y = np.array(data[predict])         # Just the G3 value

# Train the model if a saved model doesn't exist 
if not os.path.exists("studentmodel.pickle"):
    best = 0
    niter = 10000
    for count in range(niter):

        if count % 100 == 0: # Display completion status
            os.system('cls')
            print('Training... %.2f %%' %((count/niter)*100))

        x_train, x_test, y_train, y_test = sklearn.model_selection.train_test_split(X,Y,test_size = 0.1)

        # Training 
        linear = linear_model.LinearRegression()
        linear.fit(x_train,y_train)
        acc = linear.score(x_test,y_test)
        # print(acc)

        # Save trained model as pickle if its better
        if acc > best:
            best = acc
            with open("studentmodel.pickle","wb") as f:
                pickle.dump(linear,f)
    else:
        # Print results
        os.system('cls')
        print('Training complete,model a saved as pickle')
        print('Model Accuracy = %.2f %%' %(best*100))

        # Save model stats to a text file 
        f = open("model_stats.txt","w+")
        f.truncate()
        f.write('Model Accuracy = %.2f %%' %(best*100))
        f.close()
else:
    print('Using previously trained model')
    x_train, x_test, y_train, y_test = sklearn.model_selection.train_test_split(X,Y,test_size = 0.1)

pickle_in = open("studentmodel.pickle","rb")
linear = pickle.load(pickle_in)

# print("Co: ", linear.coef_)
# print("Intercept: \n", linear.intercept_)

predictions = linear.predict(x_test)

p = 'G1' 
style.use("ggplot")
plt.scatter(data[p],data['G3'])
plt.xlabel(p)
plt.ylabel('Final Grade')
plt.show()

# for i in range(len(predictions)):
    # print(predictions[i],x_test[i],y_test[i])