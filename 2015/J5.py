n = input()
k = input()
valid_strings = []


def pi_day(pieces, people, substring, mini):
        if people == 1:
            substring += str(pieces/people)
            valid_strings.append(substring)
            return

        if people == pieces:
            substring += str('1'*people)
            valid_strings.append(substring)
            return

        for i in range(mini, pieces/people+1):
            substring += str(i)
            pi_day(pieces-i, people-1, substring, i)
            substring = substring[:-1]

pi_day(n, k, '', 1)
print len(valid_strings)
