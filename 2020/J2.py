"""
author: sjay05
"""
P = input()
N = input()
R = input()

infected = N
people = N

count = 0
while True:
    people = people + (infected*R)
    infected = infected*R
    count += 1
    if people >= P:
        if people == P:
            print count+1
        else:
            print count
        break
