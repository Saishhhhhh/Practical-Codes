# Assignment No-02
# Aim: To illustrate the various functions in python.

# Problem Statement: Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. Write functions to compute following:

# a) The average score of class
# b) Highest score and lowest score of class
# c) Count of students who were absent for the test
# d) Display mark with highest frequency

def avgMarks(lst):
    sum = 0
    count = 0
    for i in range(len(lst)):
        if lst[i] != -1:
            sum = sum + lst[i]
            count += 1
    avg = sum/count
    print("The average marks of the class is: ",avg)

def maxMin(lst):
    max = -1
    min = 101

    for i in range(len(lst)):
        if lst[i] != -1:
            if(lst[i] > max):
                max = lst[i]
            if(lst[i] < min):
                min = lst[i]
    print("Lowest score is: ",min)
    print("Highesh score is: ",max)

def absentees(lst):
    count = 0
    for i in range(len(lst)):
        if(lst[i] == -1):
            count = count + 1
    print("Absent Students: ",count)

def frequency(lst):
    temp = [0]*101
    for i in range(len(lst)):
        if lst[i] != -1:
            temp[lst[i]]+=1
    
    maxFreq = 0
    mostFreqMarks = -1
    for i in range(len(temp)):
        if temp[i] > maxFreq:
            maxFreq = temp[i]
            mostFreqMarks = i
    print(f"The most frequent marks are: {mostFreqMarks} and they appear {maxFreq} times")

n = int(input("Enter the number of students: "))
marks = [0]*n

print("Enter the marks (-1 for abs students): ")
for i in range(n):
    marks[i] = int(input("Enter marks: "))

avgMarks(marks)
maxMin(marks) 
absentees(marks)
frequency(marks)