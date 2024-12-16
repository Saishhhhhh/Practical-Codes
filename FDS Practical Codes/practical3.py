# Assignment no: 03

# Aim: To study and understand the concept of a bank account based transaction using Python.

# Problem definition:
# Write a Python program that computes the net amount of a bank account based a transaction log from console input. The transaction log format is shown as following: D 100 W 200 (Withdrawal is not allowed if balance is going negative. Write functions for withdraw and deposit) D means deposit while W means withdrawal. Suppose the following input is supplied to the program:
# D 300, D 300 , W 200, D 100 Then, the output should be: 500

class BankAccount:
    def __init__(self,name):
        self.name = name
        self.balance = 0

    def deposit(self, amount):
        self.balance += amount
        print(f"Deposited: {amount}. Current balance: {self.balance}")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient Balance!")
        else:
            self.balance -= amount
            print(f"Net balance: {self.balance}")

    def print_balance(self):
        print(f"Net balance: {self.balance}")

print("Welcome!")
name = input("Enter your name: ")
account = BankAccount(name)

print("Enter transactions in the format: D <amount> or W <amount>")
print("Type 'end' to finish the transaction log.")

while True:
    transaction = input("Enter a transaction: ")
    if transaction == "end":
        break
    operation,amount = transaction.split()
    amount = int(amount)

    if operation == "D":
        account.deposit(amount)
    elif operation == "W":
        account.withdraw(amount)
    else:
        print("Wrong Input...")

account.print_balance()