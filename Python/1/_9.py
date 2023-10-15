#Write a Python program that checks the strength of a password entered by a user. The program should assess the password based on criteria like length, use of uppercase and lowercase letters, digits, and special characters. Use control structures and arrays to provide a detailed evaluation.

def check_password_strength(password):
    if len(password) < 8:
        print("Password is too short")
        return
    uppercase = False
    lowercase = False
    digit = False
    special = False
    for i in range(0, len(password)):
        if password[i].isupper():
            uppercase = True
        elif password[i].islower():
            lowercase = True
        elif password[i].isdigit():
            digit = True
        else:
            special = True
    if uppercase and lowercase and digit and special:
        print("Password is strong")
    else:
        print("Password is weak")

password = input("Enter password: ")
check_password_strength(password)

