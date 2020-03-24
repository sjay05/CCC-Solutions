// Iterative Approach 
// Works on DMOJ and Official CCC Grader

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int cost = 0;
    while (n >= 1) {
        if (n == 1) printf("%d\n", cost); break;
        int i = n;
        while (true) {
            if (i == 1) break;
            else {
                if (n % i == 0 && i < n) break;
                else i -= 1;
            }
        }
        if (i == 1) {
            n -= 1;
            cost += n/1;
        } else {
            int ext = i;
            n = n - ext;
            cost += n/ext;
        }
    }
}
