#  Implement a Python function that checks if a given string is accepted by a DFA that
# recognizes the pattern "ab*c".

import re

def match(string):
    if re.match(r'^ab*c$', string):
        return True
    return False

print(match(''))
print(match('a'))
print(match('aa'))
print(match('ab'))

print(match('ac'))
print(match('abc'))
print(match('abbc'))
