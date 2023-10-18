def area_of_circle(r):
    return 3.14 * r * r


def perimeter_of_circle(r):
    return 2 * 3.14 * r


def area_of_rectangle(l, b):
    return l * b


def perimeter_of_rectangle(l, b):
    return 2 * (l + b)


def area_of_triangle(b, h):
    return 0.5 * b * h


def perimeter_of_triangle(a, b, c):
    return a + b + c


def main():
    print(area_of_circle(1))
    print(perimeter_of_circle(1))
    print(area_of_rectangle(1, 2))
    print(perimeter_of_rectangle(1, 2))
    print(area_of_triangle(1, 2))
    print(perimeter_of_triangle(1, 2, 3))


if __name__ == "__main__":
    main()
