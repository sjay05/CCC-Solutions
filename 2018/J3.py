a = 0
b = raw_input()
c = raw_input()
d = raw_input()
e = raw_input()

final_value = [[a, b, b+c, b+c+d, b+c+d+e], [b, a, c, c+d, c+d+e], [b+c, b, a, d, d+e], [b+c+d, d+e+c, d, a, e], [b+c+d+e, c+d+e, d+e, e, a]]


for row in final_value:
    print row

