# Write a Python program to construct a DFA that accepts binary strings ending in '01'.


import re

def match(string):
    if re.match(r'^[01]*01$', string):
        return True
    return False

print(match(''))
print(match('0'))
print(match('1'))
print(match('00'))
print(match('01'))
print(match('10'))
print(match('11'))
