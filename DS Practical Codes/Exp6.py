# %% [markdown]
# ## Lab Assignment 6 
# 
# Title: Data Analytics III 
#  
# PROBLEM STATEMENT: 
#  
# 1. Implement Simple Naïve Bayes classification algorithm using Python/R on iris.csv dataset. 
#  
# 2. Compute Confusion matrix to find TP, FP, TN, FN, Accuracy, Error rate, Precision, Recall on the given 
# dataset.

# %%
# Exp6.py
# !pip install pandas numpy scikit-learn
import numpy as np
import pandas as pd

from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import confusion_matrix, classification_report, accuracy_score

# %%
from sklearn.datasets import load_iris

iris = load_iris()
X = iris.data
y = iris.target
class_names = iris.target_names

# %%
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.20, random_state=8
)

# %%
model = GaussianNB()
model.fit(X_train, y_train)

# %%
y_pred = model.predict(X_test)

# %%
cm = confusion_matrix(y_test, y_pred)

print("Confusion Matrix:\n", cm)

# %%
# Classification Report
print("\nClassification Report:\n")
print(classification_report(y_test, y_pred))

# TP, FP, FN, TN for each class

for i in range(len(class_names)):

    TP = cm[i, i]

    FP = cm[:, i].sum() - TP

    FN = cm[i, :].sum() - TP

    TN = cm.sum() - (TP + FP + FN)

    print(f"\nClass Name: {class_names[i]}")
    print(f"True Positive (TP): {TP}")
    print(f"False Positive (FP): {FP}")
    print(f"False Negative (FN): {FN}")
    print(f"True Negative (TN): {TN}")

# %%
# Accuracy
accuracy = accuracy_score(y_test, y_pred)
error_rate = 1 - accuracy

# %%
print(f"\nAccuracy: {accuracy:.2f}")
print(f"Error Rate: {error_rate:.2f}")


