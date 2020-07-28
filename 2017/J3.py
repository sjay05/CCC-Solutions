"""
author: sjay05
"""
# a = input("a-value?")
# b = input("b-value?")
# c = input("c-value?")
# d = input("d-value?")
# t = input("t-value?")

a,b = map(int, raw_input().split())
c,d = map(int, raw_input().split())
t = input()

def find_distance(a, b, c, d):
    return (c - a) + (d - b)

def can_drive(a, b, c, d, t):
    min_distance = find_distance(a, b, c, d)
    if min_distance % 2 == 0 and t % 2 == 0:
        return "Y"
    elif min_distance % 2 != 0 and t % 2 != 0:
        return "Y"
    else:
        return "N"

answer = can_drive(a, b, c, d, t)
print answer
