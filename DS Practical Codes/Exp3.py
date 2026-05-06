# %% [markdown]
# # Descriptive Statistics Tutorial

# %%
# Exp3.py
# !pip install pandas numpy seaborn scikit-learn
import pandas as pd
import numpy as np
import seaborn as sns

# %%
url_credit = 'https://raw.githubusercontent.com/JWarmenhoven/ISLR-python/master/Notebooks/Data/Credit.csv'
df_credit = pd.read_csv(url_credit, index_col=0)
df_credit

# %%
# Create categorical 'Age_Group' variable by binning the numerical 'Age'
bins = [20, 30, 40, 50, 60, 70, 80, 90, 100]
labels = ['20-30', '30-40', '40-50', '50-60', '60-70', '70-80', '80-90', '90-100']
df_credit['Age_Group'] = pd.cut(df_credit['Age'], bins=bins, labels=labels, right=False)

# Calculate summary statistics of numeric 'Income' grouped by the categorical 'Age_Group'
summary_stats = df_credit.groupby('Age_Group', observed=False)['Income'].agg(['mean', 'median', 'min', 'max', 'std'])
display(summary_stats)

# %%
from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()

df_credit['Age_Group_Numeric'] = le.fit_transform(df_credit['Age_Group'].astype(str))
numeric_responses = df_credit['Age_Group_Numeric'].tolist()

print("First 30 numeric values mapped to categorical 'Age_Group' response:\n", numeric_responses[:30])

# %% [markdown]
# ### Task 2: Basic Statistical Details of Iris Species

# %%
df_iris = sns.load_dataset("iris")

df_iris.head()

setosa_stats = df_iris[df_iris['species'] == 'setosa'].describe()
versicolor_stats = df_iris[df_iris['species'] == 'versicolor'].describe()
virginica_stats = df_iris[df_iris['species'] == 'virginica'].describe()

print("--- Iris-setosa Statistics ---")
display(setosa_stats)

print("\n--- Iris-versicolor Statistics ---")
display(versicolor_stats)

print("\n--- Iris-virginica Statistics ---")
display(virginica_stats)


