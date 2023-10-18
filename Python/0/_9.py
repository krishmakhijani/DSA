def count_upper_and_lower_case_letters(s):
    upper = 0
    lower = 0
    for c in s:
        if c.isupper():
            upper += 1
        elif c.islower():
            lower += 1
    return upper, lower


def main():
    s = input("Enter a string: ")
    upper, lower = count_upper_and_lower_case_letters(s)
    print("Upper case letters: ", upper)
    print("Lower case letters: ", lower)


if __name__ == "__main__":
    main()