# Write a python program to print diamond  numbers.


def print_diamond_numbers(n):
    for i in range(1, n+1):
        for j in range(1, n-i+1):
            print(" ", end="")
        for j in range(1, i+1):
            print(j, end="")
        for j in range(i-1, 0, -1):
            print(j, end="")
        print()
    for i in range(n-1, 0, -1):
        for j in range(1, n-i+1):
            print(" ", end="")
        for j in range(1, i+1):
            print(j, end="")
        for j in range(i-1, 0, -1):
            print(j, end="")
        print()



n = 5
print_diamond_numbers(n)