/* CCC '02 S4 - Bridge Crossing */
#include <bits/stdc++.h>

using namespace std;

/*
This solution utilizes a dynamic programming approach.
Two main array's are maintained, dp and group. Specifically,
dp[i] is the optimal time for the first i people. group[i] 
contains the length of the group with i as the last person.

For each i (person), we are trying to find which group would
be best to place in order to keep the time minimal. Since we
are given M as the total number of people there can be in 1 
group, we can loop over [1..M]. So we loop over [1...q] as i
and [1...m] as j, the answer for dp[i] lies within the answer
of dp[i-j]. However we can only place i in one of the groups.
So we maintain a (max) variable, to check if we can place i 
in a group that produces a smaller result. This way, we start
by solving sub-problems and make our way up to solving the 
whole problem. The final answer will be dp[q]. *the DP approach
is quite similar to Longest Increasing Subsequence.

For example, if our sample input is:
2 5
alice 1
bob 5
charlie 5
dobson 3
eric 3

Our DP array will be:
People = alice bob charlie dobson eric
DP     =   0    1     5      6     9 


To form the groups, we maintain a group array. group[i] 
contains the length of the group with i as the last person.
This is how we will build our groups:

Index   =  0 1 2 3 4
People  =  a b c d e
group[] =  0 0 1 2 3

To get the group that [e] is in, we can tell that group[e]
is 3. This means e is in a group that starts from index(3).
Index(3) is d. So the group for i is [group[i]...index[i]].
*/

#define INF INT_MAX

int main() {
    int m, q; cin >> m >> q;
    vector<int> dp(q + 1, INF), g(q + 1);
    vector<int> time(q + 1);
    vector<string> name(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> name[i] >> time[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= q; i++) {
        int ma = time[i];
        for (int j = 1; j <= m; j++) {
            if (i - j < 0)
                break;
            if (dp[i] > dp[i - j] + ma) {
                dp[i] = dp[i - j] + ma;
                g[i] = i - j;
            }
            ma = max(ma, time[i - j]);
        }
    }
    vector<vector<string>> groups;
    int i = q;
    while (i > 0) {
        int c = g[i];
        vector<string> a;
        for (int x = (c + 1); x < (i + 1); x++) 
            a.push_back(name[x]);
        
        groups.push_back(a);
        i = c;
    }
    reverse(groups.begin(), groups.end());
    cout << "Total Time: " << dp[q] << endl;
    for (auto u : groups) {
        string s = "";
        for (auto x : u)
            s += x + " ";

        cout << s << endl;
    }
}