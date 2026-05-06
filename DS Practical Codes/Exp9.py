# %% [markdown]
# ## Lab Assignment 9 
# Title: Data Visualization II 
#  
# PROBLEM STATEMENT: 
#  
# 1. Use the inbuilt dataset 'titanic' as used in the above problem. Plot a box plot for distribution of age with 
# respect to each gender along with the information about whether they survived or not. (Column names : 'sex' 
# and 'age') 
# 2. Write observations on the inference from the above statistics.

# %%
# Exp9.py
# !pip install seaborn matplotlib pandas
import seaborn as sns
import matplotlib.pyplot as plt

# %%
titanic = sns.load_dataset('titanic')

titanic.head()

# %%
sns.barplot(x='sex', y='age', data=titanic)

# %%
sns.boxplot(x='sex', y='age', data=titanic)

# %%
plt.figure(figsize=(8,6))

sns.boxplot(x='sex', y='age', hue='survived', data=titanic)

plt.title("Age Distribution by Gender and Survival")
plt.xlabel("Gender")
plt.ylabel("Age")

plt.show()

# %% [markdown]
# ### 🔹 **Observations:**
# 
# 1. The age distribution of passengers varies across gender and survival categories.
# 2. Female passengers generally show a wider spread in age compared to males.
# 3. Among male passengers, younger individuals have a higher survival rate compared to older males.
# 4. Female passengers have a higher survival rate across most age groups.
# 5. The box plot shows several outliers, indicating presence of passengers with extreme ages.
# 6. The median age differs between survived and non-survived groups, indicating age influences survival probability.

# %% [markdown]
# ### 🔹 **Inference:**
# 
# * Survival chances were higher for **females and younger passengers**.
# * Older male passengers had comparatively **lower survival probability**.
# * The presence of outliers shows variation in passenger ages beyond typical ranges.

# %% [markdown]
# 


