# %% [markdown]
# ## Lab Assignment 8 
# 
# Title: Data Visualization I 
#  
# PROBLEM STATEMENT: 
# 1. Use the inbuilt dataset 'titanic'. The dataset contains 891 rows and contains information about the 
# passengers who boarded the unfortunate Titanic ship. Use the Seaborn library to see if we can find any 
# patterns in the data. 
# 2. Write a code to check how the price of the ticket (column name: 'fare') for each passenger is distributed by 
# plotting a histogram.

# %%
# Exp8.py
# !pip install seaborn matplotlib pandas
import seaborn as sns
import matplotlib.pyplot as plt

# %%
titanic = sns.load_dataset('titanic')

# View first 5 rows
titanic.head()

# %%
print(titanic.info())
print(titanic.describe())

# %%
sns.countplot(x='survived', hue='sex', data=titanic)
plt.title("Survival based on Gender")
plt.show()

# %%
sns.countplot(x='survived', hue='class', data=titanic)
plt.title("Survival based on Class")
plt.show()

# %%
sns.histplot(titanic['age'].dropna(), bins=30)
plt.title("Age Distribution")
plt.show()

# %%
sns.histplot(titanic['fare'], bins=30)
plt.title("Fare Distribution")
plt.xlabel("Fare")
plt.ylabel("Frequency")
plt.show()

# %% [markdown]
# # Patterns Observed in Titanic Dataset
# 
# 1. Female passengers had a higher survival rate compared to male passengers.
# 
# 2. First-class passengers were more likely to survive than second and third-class passengers.
# 
# 3. Most passengers belonged to third class.
# 
# 4. The age distribution shows that most passengers were between 20 and 40 years old.
# 
# 5. The fare distribution is positively skewed, meaning most passengers paid low fares while only a few passengers paid very high fares.
# 
# 6. A large concentration of fare values appears near 0 because many passengers had low ticket prices compared to a few high-paying passengers.

# %%
sns.histplot(titanic['fare'], bins=50)
plt.title("Fare Distribution (More Bins)")
plt.xlabel("Fare")
plt.ylabel("Frequency")
plt.show()

# %% [markdown]
# Most passengers paid low fare, few paid very high → skewed distribution

# %% [markdown]
# 


