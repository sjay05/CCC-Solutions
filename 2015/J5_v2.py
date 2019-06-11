pieces = 120
people = 70
cache = {}


def pi_day(n, k, minimum):
    if k == 1 or n == k:
        return 1

    t = 0
    for i in range(minimum, n/k+1):
        t += pi_day(n-i, k-1, i)

    return t


print pi_day(pieces, people, 1)

