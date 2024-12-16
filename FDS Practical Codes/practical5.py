#Assignment No- 05

# Aim: To illustrate the various sorting techniques.

# Problem Statement: Write a Python program to store first year percentage of students in array. Write function for sorting array of floating-point numbers in ascending order using a) Selection Sort
# b) Bubble sort and display top five scores

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def display_top_5(arr):
    arr.sort()  
    top_5_scores = arr[-5:][::-1]  
    print("Top 5 scores: ", top_5_scores)

n = int(input("Enter the number of students: "))
scores = []

print("Enter the percentages of students:")
for i in range(n):
    score = float(input(f"Student {i+1} percentage: "))
    scores.append(score)

    
bubble_sort(scores)
print("\nSorted using Bubble Sort:", scores)
display_top_5(scores)  

    
selection_sort(scores)
print("\nSorted using Selection Sort:", scores)
display_top_5(scores)  


