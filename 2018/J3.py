a = 0
b = 3
c = 10
d = 12
e = 5

final_value = [[a, b, b+c, b+c+d, b+c+d+e], [b, a, c, c+d, c+d+e], [b+c, b, a, d, d+e], [b+c+d, d+e+c, d, a, e], [b+c+d+e, c+d+e, d+e, e, a]]


for row in final_value:
    print row

    
