# %% [markdown]
# ## Lab Assignment 2 
# Title: Data Wrangling II 
#  
# PROBLEM STATEMENT: 
#  
# Create an “Academic performance” dataset of students and perform the following operations using Python. 
# 1. Scan all variables for missing values and inconsistencies. If there are missing values and/or 
# inconsistencies, use any of the suitable techniques to deal with them. 
# 2. Scan all numeric variables for outliers. If there are outliers, use any of the suitable techniques to deal with 
# them. 
# 3. Apply data transformations on at least one of the variables. The purpose of this transformation should be 
# one of the following reasons: to change the scale for better understanding of the variable, to convert a non- 
# linear relation into a linear one, or to decrease the skewness and convert the distribution into a normal 
# distribution. 

# %%
# Exp2.py
# !pip install pandas numpy seaborn matplotlib
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

# %% [markdown]
# ### 1. Create Dataset

# %%
np.random.seed(42)
data = {
    'Student_ID': range(1, 101),
    'Math_Score': np.random.normal(70, 15, 100),
    'Reading_Score': np.random.normal(75, 12, 100),
    'Absences': np.random.exponential(5, 100) # Purposely For Creating Right Skewed Data
}
df = pd.DataFrame(data)

df.loc[5:10, 'Math_Score'] = np.nan #Adding Missing Values 
df.loc[20, 'Math_Score'] = -50  # Adding Inconsistency
df.loc[50, 'Reading_Score'] = 200  #Adding Outliers

df.head(25)

# %% [markdown]
# ### 2. Scan for Missing Values

# %%
print("Missing values initially:\n", df.isnull().sum())

# %% [markdown]
# ### 3. Handle Inconsistencies

# %%
df.loc[df['Math_Score'] < 0, 'Math_Score'] = np.nan
print("Missing values after removing inconsistencies:\n", df.isnull().sum())

# %% [markdown]
# ### 4. Impute Missing Values

# %%
df['Math_Score'] = df['Math_Score'].fillna(df['Math_Score'].median())
print("Missing values after imputation:\n", df.isnull().sum())

# %% [markdown]
# ### 5. Scan for Outliers

# %%
plt.figure(figsize=(6, 4))
sns.boxplot(x=df['Reading_Score'])
plt.title('Before Outlier Handling - Reading Score')
plt.show()

# %% [markdown]
# ### 6. Handle Outliers

# %%
Q1 = df['Reading_Score'].quantile(0.25)
Q3 = df['Reading_Score'].quantile(0.75)
IQR = Q3 - Q1
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR

df['Reading_Score'] = np.clip(df['Reading_Score'], lower_bound, upper_bound)

plt.figure(figsize=(6, 4))
sns.boxplot(x=df['Reading_Score'])
plt.title('After Outlier Handling - Reading Score')
plt.show()

# %% [markdown]
# ### 7. Analyze Skewed Variables

# %%
plt.figure(figsize=(6,4))
sns.histplot(df['Absences'], kde=True)
plt.title('Original Skewed Absences Distribution')
plt.show()

# %% [markdown]
# ### 8. Apply Data Transformation

# %%
df['Absences_Log'] = np.log1p(df['Absences'])

plt.figure(figsize=(6,4))
sns.histplot(df['Absences_Log'], kde=True)
plt.title('Log Transformed Absences (Normalizing Skewness)')
plt.show()


