x = input("Month?")
y = input("Day")

def Junior(x,y):
    if x == 2 and y == 8:
        print 'Special'
    elif x == 2 and y < 8:
        print 'Before'
    elif x < 2:
        print 'Before'
    elif x == 2 and y > 8:
        print 'After'
    elif x > 2:
        print 'After'

print Junior(x,y)

