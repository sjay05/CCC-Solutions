rules = []
for i in range(3):
    rules.append(raw_input().split())

seperated_values = raw_input().split()
S = int(seperated_values[0])
I = seperated_values[1]
F = seperated_values[2]

def get_rules(s):
    possible_rules = []
    for i in range(len(s)):
        for j in range(len(rules)):
            if s.startswith(rules[j][0], i):
                possible_rules.append([j, i])

    return possible_rules

storage = set()


def recursive_rules(s, steps):
    r = True
    if s == F:
        print_steps(steps)
        return False
    elif len(steps) == S:
        return True
    # elif s in storage:
    #     return True
    else:
        p_rules = get_rules(s)
        for i in p_rules:
            rule_number = i[0]
            substution_s = rules[rule_number][1]
            a = rules[rule_number][0]
            start_index = i[1]
            new_s = s[:start_index] + substution_s + s[start_index+len(a):]
            steps.append([rule_number+1, start_index+1, new_s])
            r = recursive_rules(new_s, steps)
            steps.remove(steps[len(steps)-1])
            if not r:
                break

    if not r:
        return False
    else:
    #     storage.add(s)
        return True

def print_steps(steps):
    for i in steps:
        print str(i[0]) + " " + str(i[1]) + " " + i[2]

recursive_rules(I, [])


