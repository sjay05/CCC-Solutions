#include <bits/stdc++.h>
using namespace std;

int A, B, N;
vector<int> hotels = {0, 990, 1010, 1970, 2030, 2940, 3060, 
                 3930, 4060, 4970, 5030, 5990, 6010, 7000};


int find_paths(int n, int i) {
    int paths = 0;
    if (n >= 7000) {
        return 1;
    }

    else {
        for (int x = i+1; x < hotels.size(); x++) {
            if (hotels[x] - n >= A && hotels[x] - n <= B) {
                paths += find_paths(hotels[x], x);
            } else if (hotels[i] - n > B) {
                break;
            }
        }
    }
    return paths;
}

int main() {
    scanf("%d\n%d\n%d", &A, &B, &N);
    while (N--) {
        int x; scanf("%d", &x);
        hotels.push_back(x);
    }
    sort(hotels.begin(), hotels.end());
    printf("%d\n", find_paths(0, 0));
}