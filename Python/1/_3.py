# Write a python program to count the Occurrences of a Specific Element in an Array.

def count_occurrences(arr, element):
    count = 0
    for i in range(0, len(arr)):
        if arr[i] == element:
            count += 1
    return count

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
element = 3
count = count_occurrences(arr, element)
print("Number of occurrences of element ", element, " is: ", count)

