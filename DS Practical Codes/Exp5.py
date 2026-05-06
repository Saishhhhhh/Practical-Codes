# %% [markdown]
# ## Lab Assignment 5 
# 
# Title: Data Analytics II 
#  
# PROBLEM STATEMENT: 
#  
# 1. Implement logistic regression using Python/R to perform classification on Social_Network_Ads.csv 
# dataset. 
# 2. Compute Confusion matrix to find TP, FP, TN, FN, Accuracy, Error rate, Precision, Recall on the given 
# dataset. 

# %%
# Exp5.py
# !pip install pandas numpy matplotlib scikit-learn
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix

# %%
dataset = pd.read_csv('Social_Network_Ads.csv')
dataset.head()

# %%
X = dataset.iloc[:, [2, 3]].values   # Age, Estimated Salary
y = dataset.iloc[:, 4].values        # Purchased

# %%
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=0
)

# %%
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# %%
model = LogisticRegression()
model.fit(X_train, y_train)

# %%
y_pred = model.predict(X_test)

# %%
cm = confusion_matrix(y_test, y_pred)
print("Confusion Matrix:\n", cm)

# %%
TN = cm[0][0]
FP = cm[0][1]
FN = cm[1][0]
TP = cm[1][1]

print("TP:", TP)
print("FP:", FP)
print("TN:", TN)
print("FN:", FN)

# %%
accuracy = (TP + TN) / (TP + TN + FP + FN)
error_rate = 1 - accuracy
precision = TP / (TP + FP)
recall = TP / (TP + FN)

print("Accuracy:", accuracy)
print("Error Rate:", error_rate)
print("Precision:", precision)
print("Recall:", recall)

# %%
from sklearn.metrics import classification_report

print(classification_report(y_test, y_pred))


