inputs = []
while True:
    x = raw_input()
    if x == "X":
        break
    inputs.append(x)


for n in inputs:
    while True:
        a = n.find("ANA")
        b = n.find("BAS")
        if a == -1 and b == -1:
            break
        if a != -1:
            n = n.replace("ANA", "A")
        if b != -1:
            n = n.replace("BAS", "A") 
    
    if n == "A":
        print "YES"
    else:
        print "NO"