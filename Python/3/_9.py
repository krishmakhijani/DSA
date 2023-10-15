#  Develop a Python function that converts a simple regular expression like "a(b|c)*" into an
# equivalent NFA.

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
