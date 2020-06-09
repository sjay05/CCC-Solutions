#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MXN = 1000005;
int j, a;
char arr[MXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> j >> a;
    for (int i=1; i<=j; i++) {
        char c; cin >> c;
        if (c == 'M') arr[i] = 'M';
        else if (c == 'S') arr[i] = 'S';
        else if (c == 'L') arr[i] = 'L';
    }
    int ans = 0;
    for (int i=0; i<a; i++) {
        char c; int n; cin >> c >> n;
        if (arr[n] == c) {
            ans++; arr[n] = 'X';
        }
    }
    printf("%i\n",ans);
}