"""
author: sjay05
"""
# --- INPUT HANDLING ---
from sys import stdin

input = stdin.readline


# --- INPUT HANDLING ---

# --- START OF Templates ----
def build(val, length):
    return [val] * length


def p2d(matrix):
    for line in matrix:
        print line


def readStr():
    return input()


def readInt():
    return int(input())


def readStrArr():
    arr = input().split()
    return arr


def readIntArr():
    arr = input().split()
    arr = [int(i) for i in arr]
    return arr


def pContents(x):
    for i in x:
        print i


# ---- END OF Templates ---

# --- CONSTANTS ----
weather = {}


# --- Functions ---
def helper():
    coldest = 201
    Acity = ""
    for city in weather.keys():
        if weather[city]<coldest:
            Acity = city
            coldest = weather[city]

    return Acity


if __name__ == '__main__':
    while True:
        city, temperature = readStrArr()
        temperature = int(temperature)
        weather[city] = temperature
        if city == "Waterloo":
            break

    print helper()
