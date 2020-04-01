# CCC '20 J5/S2 - Escape Room

## Subtask 1 - 5:
For partial points, one can utilize the Breath First Search Algorithm and apply it to this problem. For any position `(r,c)`, we can iterate over the array to find all cells `(a,b) `. "Breadth First Search" on all neighbors, and if a neighbor is ever  ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B100%7D%20%28M%2C%20N%29) it means that a path exists. 

However, the described approach is too slow, and TLE's on subtask 6 and 7 yielding a result of 11/15.

## Subtask 6 - 7:
For the last two subtasks, the algorithm must be optiimzed. We notice that for every node, we are iterating over the whole array to find all neighbors. If the same thing is done for thousands of nodes, it will result in TLE, and a lot of operations will be repeated. We are going to maintain the value of `r*c` in an array so to find all neighbors given a node, it will just be a O(1) operation to get an array of all neighbors.

Implementation of optimization can be done while reading input. 

```c++
vector<vector<pii>> helper(1e6+5);
// for each value, we are storing an array of coords...
cin >> m >> n; int x;
for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
        cin >> x; 
        helper[x].push_back({i+1, j+1}); 
        // +1 to i & j since it is 1-indexed.
    }
}

```