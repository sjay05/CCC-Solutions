input = "One :-( of :-) each."

i = 0
n = 0
hap = 0
sad = 0

while i < len(input):
    if input[i] == ")":
        if input[i-2:i+1] == ":-)":
            hap += 1
            i += 1
    elif input[i] == "(":
        if input[i-2:i+1] == ":-(":
            sad += 1
            i += 1
    else:
        i += 1

if hap > sad:
    print "happy"
elif sad > hap:
    print "sad"
elif sad == 0 and hap == 0:
    print "none"
elif sad == hap:
    print "unsure"

