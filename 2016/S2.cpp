
/* CCC 2016 Senior 2: Tandem Bicycle
 * author: DynamicSquid
 *
 * If we start with the slowest speed, we can get that
 * number by pairing up the fastest bicycle on one
 * country, with the fastest bicycle on the second
 * country. Then paring up the 2nd fastest bicycle
 * on one country, with the 2nd fastest bicycle on
 * the other country, and so on. And In order to get
 * the pairs, we can simply sort the arrays.
 *
 * Dmojistan: 5 4 1   // after array has been sorted
 * Pegland  : 6 4 2
 * Total Speed = max(5, 6) + max(4, 4) + max(1 + 2) = 12
 *
 * For the fastest speed, we can reverse an array.
 *
 * Dmojistan: 5 4 1
 * Pegland  : 2 4 6
 * Total Speed = max(5, 2) + max(4 + 4), max(1 + 6) = 15
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int question;
    cin >> question;

    int N;
    cin >> N;

    vector<int> city1(N);
    vector<int> city2(N);

    for (int a = 0; a < N; ++a)
    {
        int num;
        cin >> num;
        city1[a] = num;
    }

    for (int a = 0; a < N; ++a)
    {
        int num;
        cin >> num;
        city2[a] = num;
    }

    sort(city1.begin(), city1.end());
    sort(city2.begin(), city2.end());

    if (question == 2)
        reverse(city1.begin(), city1.end());

    int speed = 0;
    for (int a = 0; a < (int) city1.size(); ++a)
        speed += max(city1[a], city2[a]);

    cout << speed;
}
