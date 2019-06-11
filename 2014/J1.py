x = input()
y = input()
z = input()

if x == 60 and y == 60 and z == 60:
    print "Equilateral"
elif (x + y + z) == 180 and x == y or x == z or y == z:
    print "Isosceles"
elif (x + y + z) != 180:
    print "Error"
else:
    print "Scalene"