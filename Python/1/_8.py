# Write a Python program that simulates a simple guessing game. Generate a random number and have the user guess it. Provide hints like "too high" or "too low" until they guess correctly.

import random

def guessing_game():
    random_number = random.randint(1, 100)
    while True:
        guess = int(input("Guess a number between 1 and 100: "))
        if guess == random_number:
            print("You guessed correctly!")
            break
        elif guess > random_number:
            print("Too high!")
        else:
            print("Too low!")

guessing_game()
