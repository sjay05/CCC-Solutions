#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define find(i, x) x.count(i)
#define MAXN 1000000000

int N;
unordered_map<int, long long> dp;

long long func(int n){
    if (n == 1 || n == 2)
        return 1;

    if (dp[n])
        return dp[n];

    long long fin = 0, k = n;
    while (k >= 2) {
        int x = n / k, nn = n / (x + 1);
        fin += (k - nn) * func(x);
        k = nn;
    }
    dp[n] = fin;
    return fin;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    cout << func(N) << endl;
}