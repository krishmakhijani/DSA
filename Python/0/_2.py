def max_of_two_numbers(a, b):
    if a > b:
        return a
    else:
        return b


def max_of_three_numbers(a, b, c):
    return max_of_two_numbers(max_of_two_numbers(a, b), c)


def main():
    print(max_of_three_numbers(1, 2, 3))

if __name__ == "__main__":
    main()