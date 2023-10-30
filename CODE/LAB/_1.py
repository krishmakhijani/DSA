def NumberOfCarries(num1, num2):
  """Calculates the total number of carries generated while adding digits of two numbers `num1` and `num2`.

  Args:
    num1: An integer.
    num2: An integer.

  Returns:
    The total number of carries.
  """

  carry = 0
  count = 0
  while num1 > 0 or num2 > 0:
    digit1 = num1 % 10
    digit2 = num2 % 10
    sum = digit1 + digit2 + carry
    carry = sum // 10
    if carry > 0:
      count += 1
    num1 //= 10
    num2 //= 10

  return count


# Prompt the user for input.
num1 = int(input(" "))
num2 = int(input(" "))

# Calculate the number of carries.
carries = NumberOfCarries(num1, num2)

# Print the result.
print("", carries)