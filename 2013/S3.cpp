/*
 * Author: DynamicSquid
 */

#include <iostream>
#include <vector>
using namespace std;

int T, wins = 0;

void score(vector<vector<int> > games, vector<int> points) {
    if (games.empty()) {
        int max = 0;
        for (size_t a = 1; a < points.size(); ++a) {
            if (points[a] > points[max])
                max = a;
        }

        for (size_t a = 0; a < points.size(); ++a) {
            if (a != max && points[a] == points[max])
                return;
        }

        if (max == T - 1)
            wins++;

        return;
    }

    int t1 = games.back()[0] - 1;
    int t2 = games.back()[1] - 1;
    games.pop_back();

    points[t1] += 3;
    score(games, points);
    points[t1] -= 3;

    points[t2] += 3;
    score(games, points);
    points[t2] -= 3;

    points[t1]++;
    points[t2]++;
    score(games, points);
    points[t1]--;
    points[t2]--;
}

int main() {
    int G;
    cin >> T >> G;

    vector<vector<int> > games{
        { 1, 2 }, { 1, 3 }, { 1, 4 },
        { 2, 3 }, { 2, 4 },
        { 3, 4 }
    };

    vector<int> points{ 0, 0, 0, 0 };

    for (int a = 0; a < G; ++a) {
        int t1, t2, s1, s2;
        cin >> t1 >> t2 >> s1 >> s2;

        for (size_t b = 0; b < games.size(); ++b) {
            if ((games[b][0] == t1 && games[b][1] == t2) || (games[b][0] == t2 && games[b][1] == t1)) {
                games.erase(games.begin() + b);
                break;
            }
        }

        if (s1 > s2) {
            points[t1 - 1] += 3;
        }
        else if (s1 < s2) {
            points[t2 - 1] += 3;
        }
        else {
            points[t1 - 1]++;
            points[t2 - 1]++;
        }
    }

    score(games, points);

    cout << wins;
}
