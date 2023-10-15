# Write a Python program that performs matrix multiplication. Ask the user to input two matrices as lists of lists (2D arrays) and then multiply them if possible. Make sure to check if the matrices are compatible for multiplication and handle errors gracefully.

def matrix_multiplication(matrix1, matrix2):
    if len(matrix1[0]) != len(matrix2):
        print("Matrices are not compatible for multiplication")
        return
    result = []
    for i in range(0, len(matrix1)):
        row = []
        for j in range(0, len(matrix2[0])):
            row.append(0)
        result.append(row)
    for i in range(0, len(matrix1)):
        for j in range(0, len(matrix2[0])):
            for k in range(0, len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result


def read_matrix():
    rows = int(input("Enter number of rows: "))
    columns = int(input("Enter number of columns: "))
    matrix = []
    for i in range(0, rows):
        row = []
        for j in range(0, columns):
            element = int(input("Enter element: "))
            row.append(element)
        matrix.append(row)
    return matrix


matrix1 = read_matrix()
matrix2 = read_matrix()
result = matrix_multiplication(matrix1, matrix2)
print("Result of multiplication is: ", result)
