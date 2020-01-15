inputs = raw_input().split()

a = 0
b = int(inputs[0])
c = int(inputs[1])
d = int(inputs[2])
e = int(inputs[3])

final_value = [[a, b, b+c, b+c+d, b+c+d+e], [b, a, c, c+d, c+d+e], [b+c, b, a, d, d+e], [b+c+d, d+e+c, d, a, e], [b+c+d+e, c+d+e, d+e, e, a]]


for row in final_value:
    s = ""
    for i in row:
        if i != row[-1]:
            s += str(i)+" "
        else:
            s += str(i)
    print s 
