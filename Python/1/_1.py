# Implement a python program to find the first largest and second largest numbers in an Array. Note: should not use any built-in sorting functions or libraries.


def find_largest(arr):
    largest = arr[0]
    for i in range(1, len(arr)):
        if arr[i] > largest:
            largest = arr[i]
    return largest

arr= [1, 2, 3, 4, 5, 6, 7, 8, 9]
largest = find_largest(arr)
print("Largest number is: ", largest)