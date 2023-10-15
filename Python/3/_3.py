# Implement a Python script that converts a simple NFA into a DFA with two states.


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
