"""
author: sjay05
"""

# CCC '19 S5 - Triangle: The Data Structure
# Doesn't work for larger input

def find_values(i, j):
    max_list = []
    main_j = k-1
    for a in range(k):
        temp_i = i + a
        temp_j = j + a
        new_j = main_j - a
        max_list.append(triangle_ds[temp_i][temp_j])
        while new_j >= 1:
            max_list.append(triangle_ds[temp_i + 1][temp_j])
            temp_i = temp_i + 1
            new_j -= 1

    return max_list


if __name__ == '__main__':
    n_and_k = raw_input().split()
    n = int(n_and_k[0])
    k = int(n_and_k[1])
    triangle_ds = []
    for i in range(n):
        temp_list = raw_input().split()
        temp_list = [int(i) for i in temp_list]
        triangle_ds.append(temp_list)

    total_sum = 0
    for i in range(n - (k - 1)):
        for j in range(len(triangle_ds[i])):
            total_sum += max(find_values(i, j))

    print total_sum
