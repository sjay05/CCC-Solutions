"""
author: sjay05
"""
def pattern_generator(n, k, s):
    if n == 0 and k == 0:
        print s
        return
    if n == 0:
        return
    else:
        if k >= 1:
            pattern_generator(n-1, k-1, s+"1")
        pattern_generator(n-1, k, s+"0")


if __name__ == '__main__':
    first = input()
    all_inputs = []
    for i in range(first):
        n_and_k = raw_input().split()
        all_inputs.append(n_and_k)

    for i in range(len(all_inputs)):
        print "The bit patterns are"
        n = int(all_inputs[i][0])
        k = int(all_inputs[i][1])
        pattern_generator(n, k, "")
