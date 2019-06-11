# Attempted Recursion "NOT WORKING"
from collections import OrderedDict
sub_rule_map = OrderedDict()

for l in range(3):
    rule_input = raw_input().rsplit()
    sub_rule_map[rule_input[0]] = rule_input[1]

output_line_spec = raw_input().rsplit()

S = int(output_line_spec[0])
I = output_line_spec[1]
F = output_line_spec[2]

target_found = False
final_list = []

def search_and_find(values, word):
    for search in range(len(values)):
        if values[search] == word:
            return search+1

def apply_sub_rule(r, p, w, c):
    if c > S:
        return False
    if c == S and w == F:
        return True

    # below code finally should return True or False
    for si, sk in enumerate(sub_rule_map):
        for i in range(len(w)):
            try:
                ind = w.index(sk, i)
                # replace sk in w with sv
                nw = w[:ind] + sub_rule_map[sk] + w[ind+len(sk):]
                if apply_sub_rule(si+1, i+1, nw, c+1):
                     # print job
                    final_list.append([search_and_find(sub_rule_map.keys(), sk), p+1, nw])

                    return True
            except ValueError as e:
                # i.e., sk is not found in w
                continue

    return False

apply_sub_rule(0, 0, I, 0)

o = len(final_list)-1
while o >= 0:
    print str(final_list[o][0]) + " " + \
          str(final_list[o][1]) + " " + \
          final_list[o][2]
    o -= 1



