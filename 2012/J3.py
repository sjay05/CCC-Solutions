x = int(raw_input())

count = 0
while count < x+1:
    print ('*' * x) + ('X' * x) + ('*' * x)
    count += 1

i = 0
while i < x+1:
    print (' ' * x) + ('X' * (x*2))
    i += 1
3
g = 0
while g < x+1:
    print ("*" * x) + (' ' * x) + ('*' * x)
    g += 1