#include <bits/stdc++.h>

using namespace std;

int main() {
    int S, M, L;
    scanf("%i\n%i\n%i", &S, &M, &L);
    int happi = (1*S) + (2*M) + (3*L);
    if (happi >= 10) {
        printf("Happy\n");
    } else {
        printf("sad\n");
    }
}
