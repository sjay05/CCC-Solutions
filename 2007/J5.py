#

def trucking_paths(n, index):
    total = 0
    if n == 7000:
        return 1

    elif n in memoization.keys():
        return memoization[n]

    else:
        for i in range(index+1, len(trucking_motels)):
            if A <= trucking_motels[i]-n <= B:
                total += trucking_paths(trucking_motels[i], i)
            elif trucking_motels[i]-n > B:
                break

    memoization[n] = total
    return total

if __name__ == '__main__':
    trucking_motels = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
    A = input()
    B = input()
    C = input()
    if C > 0:
        for i in range(C):
            trucking_motels.append(input())

    trucking_motels = sorted(trucking_motels)
    memoization = {}

    print trucking_paths(0, 0)
