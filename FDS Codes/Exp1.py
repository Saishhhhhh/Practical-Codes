# Aim:
# To study and understand the concept of set theory using Python.

# Problem Definition:
# In a second-year computer engineering class, group A students play cricket,
# group B students play badminton, and group C students play football.
# Write a Python program using functions to compute the following:
# 1. List of students who play both cricket and badminton.
# 2. List of students who play either cricket or badminton but not both.
# 3. Number of students who play neither cricket nor badminton.
# 4. Number of students who play cricket and football but not badminton.
# Note: Duplicate entries should be avoided, and built-in set functions are not allowed.

# Function to remove duplicate entries from a list
def removeDuplicate(d):
    lst = []
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst

# Function to find the intersection of two lists (A ∩ B)
def intersection(lst1, lst2):
    lst3 = [val for val in lst1 if val in lst2]
    return lst3

# Function to find the union of two lists (A ∪ B)
def union(lst1, lst2):
    lst3 = lst1.copy()
    for val in lst2:
        if val not in lst3:
            lst3.append(val)
    return lst3

# Function to find the difference between two lists (A - B)
def diff(lst1, lst2):
    lst3 = [val for val in lst1 if val not in lst2]
    return lst3

# Function to find the symmetric difference between two lists (A Δ B)
def sym_diff(lst1, lst2):
    D1 = diff(lst1, lst2)
    D2 = diff(lst2, lst1)
    print("Difference between Cricket and Badminton (C-B):", D1)
    print("Difference between Badminton and Cricket (B-C):", D2)
    return union(D1, D2)

# Function to find students who play both cricket and badminton
def CB(lst1, lst2):
    lst3 = intersection(lst1, lst2)
    print("\nList of students who play both cricket and badminton:", lst3)
    return len(lst3)

# Function to find students who play either cricket or badminton but not both
def eCeB(lst1, lst2):
    lst3 = sym_diff(lst1, lst2)
    print("\nList of students who play either cricket or badminton but not both:", lst3)
    return len(lst3)

# Function to find students who play neither cricket nor badminton
def nCnB(lst1, lst2, lst3):
    lst4 = diff(lst1, union(lst2, lst3))
    print("\nList of students who play neither cricket nor badminton:", lst4)
    return len(lst4)

# Function to find students who play cricket and football but not badminton
def CBnF(lst1, lst2, lst3):
    lst4 = diff(intersection(lst1, lst2), lst3)
    print("\nList of students who play cricket and football but not badminton:", lst4)
    return len(lst4)

# Main function
SEComp = []  # List to store all students in the class
n = int(input("\nEnter the number of students in SE COMP: "))
print("Enter the names of", n, "students:")
for i in range(n):
    ele = input()
    SEComp.append(ele)

print("\nOriginal list of students in SE COMP:", SEComp)

# Input list of students who play cricket
Cricket = []
n = int(input("\nEnter the number of students who play cricket: "))
print("Enter the names of", n, "students who play cricket:")
for i in range(n):
    ele = input()
    Cricket.append(ele)
Cricket = removeDuplicate(Cricket)
print("Cricket players after removing duplicates:", Cricket)

# Input list of students who play football
Football = []
n = int(input("\nEnter the number of students who play football: "))
print("Enter the names of", n, "students who play football:")
for i in range(n):
    ele = input()
    Football.append(ele)
Football = removeDuplicate(Football)
print("Football players after removing duplicates:", Football)

# Input list of students who play badminton
Badminton = []
n = int(input("\nEnter the number of students who play badminton: "))
print("Enter the names of", n, "students who play badminton:")
for i in range(n):
    ele = input()
    Badminton.append(ele)
Badminton = removeDuplicate(Badminton)
print("Badminton players after removing duplicates:", Badminton)

# Menu-driven interface
flag = 1
while flag == 1:
    print("\nMENU")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. List of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("5. Exit")
    
    ch = int(input("Enter your choice (1-5): "))
    
    if ch == 1:
        print("Number of students who play both cricket and badminton:", CB(Cricket, Badminton))
    elif ch == 2:
        print("Number of students who play either cricket or badminton but not both:", eCeB(Cricket, Badminton))
    elif ch == 3:
        print("Number of students who play neither cricket nor badminton:", nCnB(SEComp, Cricket, Badminton))
    elif ch == 4:
        print("Number of students who play cricket and football but not badminton:", CBnF(Cricket, Football, Badminton))
    elif ch == 5:
        flag = 0
        print("Thanks for using this program!")
    else:
        print("Invalid choice! Please try again.")

    if flag != 0:
        a = input("\nDo you want to continue (yes/no)? ").strip().lower()
        if a != "yes":
            flag = 0
            print("Thanks for using this program!")


# INPUT

# Enter the number of students in SE COMP: 5
# Enter the names of 5 students:
# Alice
# Bob
# Charlie
# David
# Eva


# Enter the number of students who play cricket: 3
# Enter the names of 3 students who play cricket:
# Alice
# Charlie
# Frank


# Enter the number of students who play football: 4
# Enter the names of 4 students who play football:
# Bob
# Charlie
# David
# Gary


# Enter the number of students who play badminton: 3
# Enter the names of 3 students who play badminton:
# Alice
# Eva
# Frank
