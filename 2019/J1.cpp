/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a1, b1, a2, b2, a3, b3;
    scanf("%d", &a3);
    scanf("%d", &a2);
    scanf("%d", &a1);
    scanf("%d", &b3);
    scanf("%d", &b2);
    scanf("%d", &b1);
    int a_total, b_total;
    a_total = a3*3 + a2*2 + a1;
    b_total = b3*3 + b2*2 + b1;
    if (a_total == b_total) printf("T\n");
    if (a_total > b_total) printf("A\n");
    if (a_total < b_total) printf("B\n");
}
