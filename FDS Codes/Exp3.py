# Aim: To study and understand the concept of a bank account-based transaction using Python.

# Problem Definition:
# Write a Python program that computes the net amount of a bank account based on a transaction log from console input.
# The transaction log format is as follows: 
# D 100 (Deposit), W 200 (Withdrawal). 
# Withdrawals are not allowed if the balance becomes negative. 
# Write functions for deposit and withdrawal. 
# For example, if the input is:
# D 300, D 300, W 200, D 100 
# The output should be the final balance: 500

# Function to deposit an amount into the account
def deposit(num):
    global balance
    balance += num

# Function to withdraw an amount from the account
def withdrawal(num):
    global balance
    if balance >= num:
        balance -= num
    else:
        print("Withdrawal not possible because balance is insufficient.")

# Initialize balance to zero
balance = 0

# Loop to process transactions
while True:
    # Get the transaction details from the user
    data = input("Please enter the transaction details (or type 'Exit' to end): ")
    
    # Exit the loop if 'Exit' is entered
    if data.lower() == 'exit':
        break

    # Try to process the transaction
    try:
        # Split the input into action (D/W) and amount
        action, amount_str = data.split()
        amount = int(amount_str)
        
        # Check if it is a deposit or a withdrawal
        if action.upper() == 'D':
            deposit(amount)
        elif action.upper() == 'W':
            withdrawal(amount)
        else:
            print("Invalid transaction type. Use 'D' for deposit and 'W' for withdrawal.")
        
        # Print the current balance after each transaction
        print("Balance =", balance)
    
    # Handle invalid input formats
    except ValueError:
        print("Invalid input format. Please enter in the format 'D amount' or 'W amount'.")

# Example input and output:
# Input:
# D 300
# D 300
# W 200
# D 100
# Output:
# Balance = 500
