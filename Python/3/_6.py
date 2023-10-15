#  Create a Python script to minimize a simple DFA with three states by merging equivalent
# states.

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
