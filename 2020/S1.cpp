#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<double> > nums(N);
    for (int a = 0; a < N; ++a) {
        double x, y;
        cin >> x >> y;
        nums[a] = { x, y };
    }

    sort(nums.begin(), nums.end(), [](vector<double>& one, vector<double>& two){
        return one[0] > two[0];
    });

    double time = abs(nums[0][0] - nums[1][0]);
    double dist = abs(nums[0][1] - nums[1][1]);

    for (size_t a = 1; a < nums.size() - 1; ++a) {
        double t = abs(nums[a][0] - nums[a + 1][0]);
        double d = abs(nums[a][1] - nums[a + 1][1]);
        
        if (d / t > dist / time) {
            dist = d;
            time = t;
        }
    }

    cout << fixed << setprecision(5) << dist / time;
}
