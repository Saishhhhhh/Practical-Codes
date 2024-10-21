# Aim: To illustrate the various sorting techniques.

# Problem Statement:
# Write a Python program to store first-year percentages of students in an array.
# Write functions for sorting the array of floating-point numbers in ascending order using:
# a) Selection Sort
# b) Bubble Sort
# Then, display the top five scores.

# Function for Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function for Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

# Function to display the top N scores
def display_top_scores(arr, top_n):
    if top_n > len(arr):
        top_n = len(arr)
    print(f"Top {top_n} Scores:")
    for i in range(top_n):
        print(f"{i + 1}. {arr[i]}%")

# Main function to get input and call sorting methods
def main():
    # Input the first-year percentages of students
    n = int(input("Enter the number of students: "))
    percentages = []
    
    for i in range(n):
        percentage = float(input(f"Enter the percentage for student {i + 1}: "))
        percentages.append(percentage)
    
    # Sorting using selection sort
    sorted_percentages_selection = percentages.copy()  # Create a copy to sort
    selection_sort(sorted_percentages_selection)
    print("Sorted array using Selection Sort:")
    display_top_scores(sorted_percentages_selection, 5)
    
    # Sorting using bubble sort
    sorted_percentages_bubble = percentages.copy()  # Create a copy to sort
    bubble_sort(sorted_percentages_bubble)
    print("\nSorted array using Bubble Sort:")
    display_top_scores(sorted_percentages_bubble, 5)

# Call the main function to run the program
if __name__ == "__main__":
    main()

# INPUT

# Enter the number of students: 6
# Enter the percentage for student 1: 78.5
# Enter the percentage for student 2: 82.0
# Enter the percentage for student 3: 91.2
# Enter the percentage for student 4: 69.5
# Enter the percentage for student 5: 85.3
# Enter the percentage for student 6: 88.7
