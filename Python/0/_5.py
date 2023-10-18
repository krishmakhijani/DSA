def reverse(s):
    if len(s) == 1:
        return s
    else:
        return s[-1] + reverse(s[:-1])


def is_palindrome(s):
    return s == reverse(s)


def main():
    s = input("Enter a string: ")
    print(reverse(s))
    if is_palindrome(s):
        print("Palindrome")
    else:
        print("Not Palindrome")


if __name__ == "__main__":
    main()
