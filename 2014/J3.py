n = input()
rounds = []
for i in range(n):
    line_input = raw_input().rsplit()
    for j in range(len(line_input)):
        rounds.append(int(line_input[j]))

antonia = 100
david = 100
i = 0

while i <= len(rounds) - 2:
    if rounds[i] < rounds[i+1]:
        antonia = antonia - rounds[i+1]
        i += 2
    elif rounds[i] > rounds[i+1]:
        david = david - rounds[i]
        i += 2
    elif rounds[i] == rounds[i+1]:
        i += 2

print antonia
print david

