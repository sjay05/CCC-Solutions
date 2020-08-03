"""
author: sjay05
"""
# Iterative Approach
# Works on Official CCC Grader but TLE (14th test case) on DMOJ


n = input()

cost = 0
while n >= 1:
    if n == 1:
        print cost
        break

    i = n
    while True:
        if i == 1:
            break
        else:
            if n % i == 0 and i < n:
                break
            else:
                i -= 1

    if i == 1:
        n = n - 1
        cost += (n/1)
    else:
        ext = i
        n = n - ext
        cost += (n/ext)
