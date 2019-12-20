x = input()
y = input()
z = input()

for i in range(x):
    tine_str = ""
    for j in range(3):
        tine_str += "*"
        tine_str += y * " "
    print tine_str

print "*" * (y*2 + 3)

for x in range(z):
    handle_str = ""
    handle_str += " " * (1 + y)
    handle_str += "*"
    print handle_str
