# Create a Python function to check if a given string is accepted by an NFA that recognizes
# the pattern "ab|ba" (either "ab" or "ba").

import re

def match(string):
    if re.match(r'^ab|ba$', string):
        return True
    return False

print(match(''))
print(match('a'))
print(match('aa'))
print(match('ab'))
print(match('ba'))
print(match('aba'))
print(match('bab'))
print(match('abb'))
