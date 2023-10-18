def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def main():
    n = int(input("Enter a number: "))
    if n % 2 == 0:
        print("Even")
    else:
        print("Odd")
    if is_prime(n):
        print("Prime")
    else:
        print("Not Prime")

if __name__ == "__main__":
    main()