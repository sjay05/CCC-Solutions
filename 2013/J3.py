x = input(': ')
a = 0

def unique(x):
    i = 0
    list = []
    while i < len(str(x)):
        if str(x)[i] not in list:
            list.append(str(x)[i])
            i += 1
        else:
            break

    if len(list) == 4:
        return True
    else:
        return False

if unique(x) == True:
    b = 1
    while True:
        if unique(x + b) == True:
            print x+b
            break
        else:
            b += 1
else:
    while True:
        if unique(x + a) == True:
            print x+a
            break
        else:
            a += 1


