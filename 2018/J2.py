n = raw_input("First Line:")
a = raw_input("Second Line:")
b = raw_input("Third Line:")

i = 0
c = 0
while i < int(n):
    if a[i] == b[i] and a[i] == "C":
        #print "a[%s] = %s, b[%s] = %s" % (i, a[i], i, b[i])
        c = c + 1
    i += 1

print c



    
