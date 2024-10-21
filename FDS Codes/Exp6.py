import array as arr

# Function to accept the percentage marks of the students
def accept_perc():
    a = arr.array('f', [])  # Floating-point array to store percentages
    no_stud = int(input("Enter the number of Students: "))
    for i in range(no_stud):
        a.append(float(input(f"Enter the First Year % of Student[{i}]: ")))
    return a

# Function to print the percentage marks of the students
def print_perc(a):
    for i in range(len(a)):
        print(f"\t{a[i]:.2f}", end=" ")
    print()

# Partition function for Quick Sort
def partition(a, start, end):
    pivot = a[start]  # Choose the pivot element
    low = start + 1
    high = end

    while True:
        # Move 'high' left while elements are >= pivot
        while low <= high and a[high] >= pivot:
            high -= 1

        # Move 'low' right while elements are <= pivot
        while low <= high and a[low] <= pivot:
            low += 1

        # If low and high pointers cross, exit the loop
        if low <= high:
            a[low], a[high] = a[high], a[low]  # Swap elements
        else:
            break

    # Swap pivot with element at high pointer to place it correctly
    a[start], a[high] = a[high], a[start]
    return high

# Quick Sort function
def quick_sort(a, start, end):
    if start >= end:
        return  # Base case: return when the list is already sorted
    p = partition(a, start, end)  # Partition the array
    quick_sort(a, start, p - 1)   # Sort the left part
    quick_sort(a, p + 1, end)     # Sort the right part
    return a

# Function to display the top five scores
def top_five(a):
    print("Top five scores are: ")
    cnt = len(a)
    # If fewer than 5 students, display all scores in descending order
    if cnt < 5:
        start, stop = cnt - 1, -1
    else:
        start, stop = cnt - 1, cnt - 6
    for i in range(start, stop, -1):
        print(f"\t{a[i]:.2f}", end=" ")
    print()

# Main function
def main():
    unsorted_A = arr.array('f', [])  # Array to store unsorted percentages
    flag = 1

    while flag == 1:
        print("\n1. Accept array elements")
        print("2. Display the Elements")
        print("3. Quick Sort")
        print("4. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            unsorted_A = accept_perc()  # Accept student percentages
        elif choice == 2:
            print("Elements in the array:")
            print_perc(unsorted_A)  # Display the elements
        elif choice == 3:
            if len(unsorted_A) == 0:
                print("The array is empty. Please enter elements first.")
            else:
                print("Elements after sorting using Quick Sort:")
                quick_sort(unsorted_A, 0, len(unsorted_A) - 1)  # Perform quick sort
                print_perc(unsorted_A)  # Display the sorted elements
                top_five(unsorted_A)  # Display the top five scores
        elif choice == 4:
            print("Exiting the program.")
            flag = 0
        else:
            print("Wrong choice! Please enter a valid option.")

# Driver code to start the program
if __name__ == "__main__":
    main()

# INPUT

# Enter the number of Students: 6

# Enter the First Year % of Student[0]: 89.5
# Enter the First Year % of Student[1]: 75.0
# Enter the First Year % of Student[2]: 92.3
# Enter the First Year % of Student[3]: 68.7
# Enter the First Year % of Student[4]: 85.1
# Enter the First Year % of Student[5]: 77.8

# 1. Accept array elements
# 2. Display the Elements
# 3. Quick Sort
# 4. Exit
# Enter your choice: 1
# Enter the number of Students: 3
# Enter the First Year % of Student[0]: 85.5
# Enter the First Year % of Student[1]: 90.0
# Enter the First Year % of Student[2]: 78.3

# Enter your choice: 2
# Elements in the array:
#     85.50     90.00     78.30 

# Enter your choice: 3
# Elements after sorting using Quick Sort:
#     78.30     85.50     90.00 
# Top five scores are:
#     90.00     85.50     78.30 
