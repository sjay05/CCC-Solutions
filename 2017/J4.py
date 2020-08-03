"""
author: sjay05
"""
D = input()

def simulate_time(hour, minute, time_str, value):
    for i in range(D+1):
        time_str = ''
        if minute == 59:
            hour = choose_hour(hour)
            time_str += str(hour)
            time_str += '00'
            minute = 1
        elif minute < 9:
            time_str += str(hour)
            minute += 1
            time_str += str(0) + str(minute)
        else:
            time_str += str(hour)
            minute += 1
            time_str += str(minute)

        if arithmetic_check(time_str):
            value += 1

    return value


def arithmetic_check(time_str):
    if len(time_str) == 4:
        diff = int(time_str[1]) - int(time_str[0])
        diff2 = int(time_str[2]) - int(time_str[1])
        diff3 = int(time_str[3]) - int(time_str[2])
        if diff == diff2 == diff3:
            return True

    else:
        diff = int(time_str[1]) - int(time_str[0])
        diff2 = int(time_str[2]) - int(time_str[1])
        if diff == diff2:
            return True


def choose_hour(hour):
    if hour == 11:
        return 12
    if hour == 12:
        return 1
    else:
        return hour + 1


print simulate_time(12, 0, "", 0)
