# Aim:
# To illustrate the various functions in Python.

# Problem Statement:
# Write a Python program to store the marks scored in the subject 
# "Fundamental of Data Structure" by N students in the class. 
# Write functions to compute the following:
# a) The average score of the class.
# b) The highest and lowest score of the class.
# c) The number of students who were absent for the test.
# d) Display the mark with the highest frequency.

# Function for average score of the class
def average(listofmarks):
    sum = 0
    count = 0
    for i in range(len(listofmarks)):
        if listofmarks[i] != -999:  # Ignore absent students marked as -999
            sum += listofmarks[i]
            count += 1
    avg = sum / count
    print("Total Marks:", sum)
    print("Average Marks: {:.2f}".format(avg))

# Function for highest score in the test for the class
def Maximum(listofmarks):
    for i in range(len(listofmarks)):
        if listofmarks[i] != -999:  # Ignore absent students
            Max = listofmarks[0]
            break
    for i in range(1, len(listofmarks)):
        if listofmarks[i] > Max:
            Max = listofmarks[i]
    return Max

# Function for lowest score in the test for the class
def Minimum(listofmarks):
    for i in range(len(listofmarks)):
        if listofmarks[i] != -999:  # Ignore absent students
            Min = listofmarks[0]
            break
    for i in range(1, len(listofmarks)):
        if listofmarks[i] < Min:
            Min = listofmarks[i]
    return Min

# Function to count the number of students absent for the test
def absentcount(listofmarks):
    count = 0
    for i in range(len(listofmarks)):
        if listofmarks[i] == -999:  # -999 indicates absence
            count += 1
    return count

# Function to display marks with the highest frequency
def maxFrequency(listofmarks):
    i = 0
    Max = 0
    print("Marks | Frequency")
    for j in listofmarks:
        if listofmarks.index(j) == i:  # Avoid duplicate prints
            print(j, "|", listofmarks.count(j))
            if listofmarks.count(j) > Max:
                Max = listofmarks.count(j)
                mark = j
        i += 1
    return mark, Max

# Main function
marksinFDS = []
numberofstudents = int(input("Enter the total number of students: "))
for i in range(numberofstudents):
    marks = int(input(f"Enter marks of student {i + 1} (-999 for absent): "))
    marksinFDS.append(marks)

flag = 1
while flag == 1:
    print("\n\n MENU")
    print("1. Total and Average Marks of the Class")
    print("2. Highest and Lowest Marks in the Class")
    print("3. Number of Students Absent for the Test")
    print("4. Marks with Highest Frequency")
    print("5. Exit\n")

    ch = int(input("Enter your choice (from 1 to 5): "))

    if ch == 1:
        average(marksinFDS)
        a = input("Do you want to continue (yes/no): ")
        flag = 1 if a.lower() == "yes" else 0
    elif ch == 2:
        print("Highest Score in Class:", Maximum(marksinFDS))
        print("Lowest Score in Class:", Minimum(marksinFDS))
        a = input("Do you want to continue (yes/no): ")
        flag = 1 if a.lower() == "yes" else 0
    elif ch == 3:
        print("Number of Students Absent for the Test:", absentcount(marksinFDS))
        a = input("Do you want to continue (yes/no): ")
        flag = 1 if a.lower() == "yes" else 0
    elif ch == 4:
        mark, freq = maxFrequency(marksinFDS)
        print(f"Highest frequency is of marks {mark} with frequency {freq}")
        a = input("Do you want to continue (yes/no): ")
        flag = 1 if a.lower() == "yes" else 0
    elif ch == 5:
        flag = 0
        print("Thanks for using this program!")
    else:
        print("!!Wrong Choice!!")
        a = input("Do you want to continue (yes/no): ")
        flag = 1 if a.lower() == "yes" else 0

# Inputs Required:
# 1. Enter the total number of students.
# 2. For each student, enter the marks (use -999 if the student was absent).
# Example Input:
# Enter the total number of students: 5
# Enter marks of student 1: 45
# Enter marks of student 2: 50
# Enter marks of student 3: -999  # Absent student
# Enter marks of student 4: 60
# Enter marks of student 5: 50
