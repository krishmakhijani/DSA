# Write a Python program to calculate the sum of even numbers and the sum of odd numbers in an array.

def find_even_odd(arr):
    even = 0
    odd = 0
    for i in range(0, len(arr)):
        if arr[i] % 2 == 0:
            even += arr[i]
        else:
            odd += arr[i]
    return even, odd

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
even, odd = find_even_odd(arr)
print("Even numbers sum is: ", even)
print("Odd numbers sum is: ", odd)

