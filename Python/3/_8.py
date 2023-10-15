#  Write a Python program to create an NFA that accepts strings with an odd number of '1's.

import re

def match(string):
    if re.match(r'^0*(10*10*)*1$', string):
        return True
    return False

print(match(''))
print(match('0'))
print(match('1'))
print(match('00'))
print(match('01'))
print(match('10'))
