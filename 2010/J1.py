n = input()
values = []

for i in range(1, n+1):
    if n-i not in values and n-i <= 5 and i <= 5:
        if n - i > 0 or n <= 5:
            values.append(i)

print len(values)