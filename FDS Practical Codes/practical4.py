# Assignment No- 04

# Aim: To illustrate the various searching techniques.

# Problem Statement: a) Write a Python program to store names and mobile numbers of your friends in sorted order on names. Search your friend from list using binary search (recursive and non- recursive). Insert friend if not present in phonebook
# b) Write a Python program to store names and mobile numbers of your friends in sorted order on names. Search your friend from list using Fibonacci search. Insert friend if not present in phonebook.


def binary_search_non_recursive(phonebook, name):
    lowerBound = 0
    upperBound = len(phonebook) - 1

    while lowerBound <= upperBound:
        mid = (lowerBound + upperBound) // 2
        if phonebook[mid][0] == name:
            return mid  # Return index if found
        elif phonebook[mid][0] < name:
            lowerBound = mid + 1
        else:
            upperBound = mid - 1
    return -1  # Return -1 if not found


# Binary Search - Recursive
def binary_search_recursive(phonebook, name, lowerBound, upperBound):
    if lowerBound > upperBound:
        return -1  # Not found
    mid = (lowerBound + upperBound) // 2
    if phonebook[mid][0] == name:
        return mid  # Return index if found
    elif phonebook[mid][0] < name:
        return binary_search_recursive(phonebook, name, mid + 1, upperBound)
    else:
        return binary_search_recursive(phonebook, name, lowerBound, mid - 1)


# Fibonacci Search
def fibonacci_search(phonebook, name):
    n = len(phonebook)
    fib_m_minus_2 = 0
    fib_m_minus_1 = 1
    fib_m = fib_m_minus_1 + fib_m_minus_2

    while fib_m < n:
        fib_m_minus_2 = fib_m_minus_1
        fib_m_minus_1 = fib_m
        fib_m = fib_m_minus_1 + fib_m_minus_2

    offset = -1
    while fib_m > 1:
        i = min(offset + fib_m_minus_2, n - 1)

        if phonebook[i][0] == name:
            return i
        elif phonebook[i][0] < name:
            fib_m = fib_m_minus_1
            fib_m_minus_1 = fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
            offset = i
        else:
            fib_m = fib_m_minus_2
            fib_m_minus_1 = fib_m_minus_1 - fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1

    if fib_m_minus_1 and phonebook[offset + 1][0] == name:
        return offset + 1

    return -1  # Not found


# Function to insert a friend into the phonebook if not found
def insert_friend(phonebook, name, mobile_number):
    # Insert in sorted order
    phonebook.append((name, mobile_number))
    phonebook.sort(key=lambda x: x[0])


# Phonebook list (sorted by names)
phonebook = [
    ("Alice", "1234567890"),
    ("Bob", "2345678901"),
    ("Charlie", "3456789012"),
    ("David", "4567890123"),
    ("Eve", "5678901234")
]

# Input name to search
name = input("Enter the name of the friend you want to search: ")

# Binary Search (Non-Recursive)
index = binary_search_non_recursive(phonebook, name)
if index != -1:
    print(f"Found {name} in phonebook at index {index}")
else:
    print(f"{name} not found in phonebook.")

# Binary Search (Recursive)
index = binary_search_recursive(phonebook, name, 0, len(phonebook) - 1)
if index != -1:
    print(f"Found {name} in phonebook at index {index}")
else:
    print(f"{name} not found in phonebook.")

# Fibonacci Search
index = fibonacci_search(phonebook, name)
if index != -1:
    print(f"Found {name} in phonebook at index {index}")
else:
    print(f"{name} not found in phonebook.")

# Insert a new friend if not found
if index == -1:
    print(f"{name} not found, adding to phonebook.")
    mobile_number = input("Enter mobile number: ")
    insert_friend(phonebook, name, mobile_number)
    print(f"{name} has been added to the phonebook.")

print("\nUpdated Phonebook:")
for entry in phonebook:
    print(f"Name: {entry[0]}, Mobile: {entry[1]}")
