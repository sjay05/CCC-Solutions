N = int(input())

villages = []
for i in range(N):
    villages.append(int(input()))

villages = sorted(villages)

distance1 = abs(villages[1]-villages[0])
min_distance = distance1

for i in range(1,len(villages)-1):
    distance2 = villages[i+1]-villages[i]
    min_distance = min(distance1/2.0+distance2/2.0, min_distance)
    distance1 = distance2

print(min_distance)
