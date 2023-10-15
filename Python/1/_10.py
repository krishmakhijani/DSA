# Write a Python program that generates the Fibonacci sequence up to a specified number of terms using a loop and stores it in an array.

def fibonacci(n):
    arr = []
    for i in range(0, n):
        if i == 0 or i == 1:
            arr.append(i)
        else:
            arr.append(arr[i-1] + arr[i-2])
    return arr

n = int(input("Enter number of terms: "))
arr = fibonacci(n)
print("Fibonacci sequence is: ", arr)
