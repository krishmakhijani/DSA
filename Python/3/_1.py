# Write a Python program to create an NFA that accepts strings containing only the letter 'a'.

import re

def match(string):
    if re.match(r'^a*$', string):
        return True
    return False

print(match(''))
print(match('a'))
print(match('aa'))
print(match('ab'))
print(match('aaa'))
print(match('aab'))
print(match('aba'))
