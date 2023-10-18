def add_complex_numbers(a, b):
    return a + b


def subtract_complex_numbers(a, b):
    return a - b


def multiply_complex_numbers(a, b):
    return a * b


def divide_complex_numbers(a, b):
    return a / b


def main():
    print(add_complex_numbers(1 + 2j, 2 + 3j))
    print(subtract_complex_numbers(1 + 2j, 2 + 3j))
    print(multiply_complex_numbers(1 + 2j, 2 + 3j))
    print(divide_complex_numbers(1 + 2j, 2 + 3j))

if __name__ == "__main__":
    main()
