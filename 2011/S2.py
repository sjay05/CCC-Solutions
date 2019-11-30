# Canadian Computing Competition: 2011 Stage 1, Senior #2

lines = int(input())
responses = []
for i in range(2*lines):
    char = input()
    responses.append(char)


def grader(response):
    correct = 0
    for j in range(lines):
        if response[j] == response[j + lines]:
            correct += 1

    return correct


print(grader(responses))
