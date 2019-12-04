n = input()
arr = []
for i in range(int(n)-1):
    arr.append(input())

def connectedTo(x):
    list = []
    for i in range(len(arr)):
        if arr[i] == str(x):
            list.append(i+1)
    return list

def ways(node, total):
    if connectedTo(node) == []:
        return 2

    for i in (connectedTo(node)):
        total = (total * ways(i, 1))

    return total+1

print(ways(n, 1)-1)