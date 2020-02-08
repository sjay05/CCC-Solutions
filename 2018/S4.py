#Does not work for large inputs
#Takes longer than 1 second to process when N>20000

N = int(input())

num_trees = N//2 if N%2==0 else N//2+1

def all_tree_yeah(N, num):
    global num_trees
    for i in range(2, N-num+1):
        wk = N//i
        if wk>2:
            num1 = wk//2 if wk%2==0 else wk//2+1
            num_trees+=num1
            all_tree_yeah(wk, num1)
        else:
            num_trees+=1

all_tree_yeah(N, num_trees)
print(num_trees)

