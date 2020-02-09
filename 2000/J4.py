from sys import stdin

input = stdin.readline

n = int(input())
streams = []

for i in range(n):
    streams.append(int(input()))

while True:
    aa = int(input())
    if aa == 77: break
    if aa == 99:
        num = int(input())
        per = int(input())
        val = streams[num-1]
        streams.remove(streams[num-1])
        streams.insert(num-1, float(per*val/100))
        streams.insert(num, float(val - float((per*val/100))))
    if aa == 88:
        s = int(input())
        val = streams[s-1] + streams[s]
        streams.remove(streams[s])
        streams.remove(streams[s-1])
        streams.insert(s-1, val)


for val in streams:
    if val / int(val) == 1.0:
        print int(val),
    else:
        print val,
