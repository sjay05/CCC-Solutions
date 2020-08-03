"""
author: sjay05
"""
main = input()
c = 0
list = []
inp = ""
while c < main:
    inp = raw_input()
    inp = inp.rsplit(" ")
    list.append(inp)
    c += 1

for i in range(len(list)):
    print list[i][1] * int(list[i][0])
