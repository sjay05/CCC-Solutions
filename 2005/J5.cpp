/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> inps;
    while (true) {
        string x;
        cin >> x;
        if (x == "X") break;
        inps.push_back(x);
    }

    for (string x : inps) {
        while (true) {
            int a = x.find("ANA");
            int b = x.find("BAS");
            if (a == -1 && b == -1) break;
            if (a != -1) x.replace(a, 3, "A");
            if (b != -1) x.replace(b, 3, "A");
        }
        if (x == "A") {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
