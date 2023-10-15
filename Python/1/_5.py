# Write a Python program that takes a list of numbers and removes all duplicates from the list, preserving the original order of elements.

def remove_duplicates(arr):
    new_arr = []
    for i in range(0, len(arr)):
        if arr[i] not in new_arr:
            new_arr.append(arr[i])
    return new_arr

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
new_arr = remove_duplicates(arr)
print("New array is: ", new_arr)

