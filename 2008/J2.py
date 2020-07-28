"""
author: sjay05
"""
inputs = []
output = ["A", "B", "C", "D", "E"]
while True:
    b = input()
    i = input()
    if b == 4:
        break
    else:
        inputs.append([b,i])


def button_1():
    temp = output[0]
    output.remove(output[0])
    output.append(temp)


def button_2():
    temp = output[4]
    output.remove(output[4])
    output.insert(0, temp)


def button_3():
    output[0],output[1] = output[1], output[0]


for pair in inputs:
    b = pair[0]
    i = pair[1]
    for x in range(i):
        if b == 1:
            button_1()
        if b == 2:
            button_2()
        if b == 3:
            button_3()

for i in output:
    print i,
