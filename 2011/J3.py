"""
author: sjay05
"""
a = input()
b = input()

count = 2
while a >= b and a >= 0 and b >= 0:
    count = count + 1
    c = a - b
    a = b
    b = c
print count
