def celsius_to_fahrenheit(c):
    return (c * 9 / 5) + 32


def fahrenheit_to_celsius(f):
    return (f - 32) * 5 / 9


def main():
    print(celsius_to_fahrenheit(0))
    print(fahrenheit_to_celsius(32))


if __name__ == "__main__":
    main()
