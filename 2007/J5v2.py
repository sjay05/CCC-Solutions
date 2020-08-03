"""
author: sjay05
"""
from sys import stdin

input = stdin.readline


def find_paths(n, i):  # n being distance travelled
    paths = 0  # i being last hotel visited (index)
    if n>=7000:
        return 1

    if n in memset:  # DP Memoization Technique
        return memset[n]

    else:
        for i in range(i + 1, len(hotels)):
            if A<=(hotels[i] - n)<=B:  # Is the distance more or equal to
                # the distance that is mandated to be driven
                # but however less than the amount on law
                paths += find_paths(hotels[i], i)  # This is a one of the valid hotels
                # to visit.
            elif (hotels[i] - n)>B:
                break  # We do not wan't to continue to search.
                # It is a waste of time.

    memset[n] = paths  # store value in memset for DP
    return paths  # This is the answer


if __name__ == "__main__":
    A = int(input())
    B = int(input())
    N = int(input())
    hotels = [0, 990, 1010, 1970, 2030, 2940, 3060,  # Store preset hotel locations
              3930, 4060, 4970, 5030, 5990, 6010, 7000]
    for i in range(N):
        hotels.append(int(input()))

    memset = {}
    hotels.sort()  # Sort for simplicity
    print find_paths(0, 0)  # find paths from 0, 0
