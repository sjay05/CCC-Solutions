#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k, x;
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%i",&k);
    for (int i=0; i<k; i++) {
        scanf("%i",&x);
        if (x == 0) {
            s.pop();
        } else {
            s.push(x);
        }
    }
    int res = 0;
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    printf("%i\n",res);
}