def sum_of_two_numbers(a, b):
    return a + b


def sum_of_three_numbers(a, b, c):
    return a + b + c


def sum_of_two_numbers_between_120_and_320(a, b):
    sum = a + b
    if sum >= 120 and sum <= 320:
        return 200
    else:
        return sum


def sum_of_three_numbers_between_120_and_320(a, b, c):
    sum = a + b + c
    if sum >= 120 and sum <= 320:
        return 200
    else:
        return sum


def main():
    print(sum_of_two_numbers(1, 2))
    print(sum_of_three_numbers(1, 2, 3))
    print(sum_of_two_numbers_between_120_and_320(1, 2))
    print(sum_of_three_numbers_between_120_and_320(1, 2, 3))

if __name__ == "__main__":
    main()