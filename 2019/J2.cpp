#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n; 
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    bool expr, fin = true;
    if (arr[0] % 2 == 0) expr = false;
    else expr = true;
    for (int i = 1; i < n; ++i) {
        if (!expr) {
            if (arr[i] % 2 == 1) fin = false;
        } else {
            if (arr[i] % 2 == 0) fin = false;
        }
    }
    if (fin) {
        if (arr[0] % 2 == 0) cout << "All numbers are even\n";
        else cout << "All numbers are odd\n";
    } else cout << "All numbers are not same\n";
}