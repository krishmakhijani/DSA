#  Develop a Python function that takes an NFA and returns the set of states that can be reached from a given state on a specific input symbol.Develop a Python function that takes an NFA and returns the set of states that can be reached from a given state on a specific input symbol.

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

