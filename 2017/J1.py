"""
author: sjay05
"""
x = input()
y = input()

def find_quadrant(x, y):
    if x > 0 and y > 0:
        return "1"
    elif x < 0 and y > 0:
        return "2"
    elif x > 0 and y > 0:
        return "3"
    else:
        return "4"

print find_quadrant(x, y)
