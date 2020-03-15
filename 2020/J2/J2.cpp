#include <bits/stdc++.h>

using namespace std;

int P, N, R;

int main() {
    scanf("%i\n%i\n%i", &P, &N, &R);
    int infected = N; int people = N;
    int count = 0;
    while (true) {
        people = people + (infected*R);
        infected = infected*R;
        count++;
        if (people >= P) {
            if (people == P) {
                printf("%i\n", count+1);
            } else {
                printf("%i\n", count);
            }
            break;
        }
    }
}