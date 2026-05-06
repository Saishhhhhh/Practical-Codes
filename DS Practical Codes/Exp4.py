# %% [markdown]
# ## Lab Assignment 4 
# 
# Title: Data Analytics I 
# PROBLEM STATEMENT: 
#  
# Create a Linear Regression Model using Python/R to predict home prices using Boston Housing Dataset 
# (https://www.kaggle.com/c/boston-housing). The Boston Housing dataset contains information about various 
# houses in Boston through different parameters. There are 506 samples and 14 feature variables in this dataset. 

# %%
# Exp4.py
# !pip install pandas matplotlib scikit-learn
# Import all the necessary libraries
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# %%
# Load the dataset and check the data 
url = "https://raw.githubusercontent.com/selva86/datasets/master/BostonHousing.csv"
df = pd.read_csv(url)
df.head()

# %% [markdown]
# | Column | Description |
# |---|---|
# | crim | Per capita crime rate by town |
# | zn | Residential land zoned for large lots |
# | indus | Proportion of non-retail business acres |
# | chas | Charles River dummy variable (1 if near river, else 0) |
# | nox | Nitric oxide concentration |
# | rm | Average number of rooms per dwelling |
# | age | Proportion of old owner-occupied units |
# | dis | Distance to employment centers |
# | rad | Accessibility to radial highways |
# | tax | Property tax rate |
# | ptratio | Pupil-teacher ratio by town |
# | b | Proportion related to Black population index |
# | lstat | Percentage of lower status population |
# | medv | Median value of owner-occupied homes |

# %%
# Perform train test split
X = df.drop('medv', axis=1)
y = df['medv']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# %%
# Create model variable and train the model
model = LinearRegression()
model.fit(X_train, y_train)

# %%
# Perform prediction and calculate error
y_pred = model.predict(X_test)

print(f"MSE: {mean_squared_error(y_test, y_pred):.2f}")
print(f"R2 Score: {r2_score(y_test, y_pred):.2f}")

# %%
# Plot Actual & Predicted rpice with linear regression line
plt.scatter(y_test, y_pred, alpha=0.7)
plt.plot([y.min(), y.max()], [y.min(), y.max()], color='red', linestyle='--')
plt.xlabel("Actual Prices")
plt.ylabel("Predicted Prices")
plt.title("Actual vs Predicted Prices")
plt.show()

# %%
sample_data = X_test.iloc[0:1]

predicted_price = model.predict(sample_data)

print("Predicted House Price:", predicted_price[0])
print("Actual House Price:", y_test.iloc[0])


