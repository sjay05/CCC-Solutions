/* CCC 2010 Senior 1: Computer Purchase
 * author: DynamicSquid
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Computer
{
    string name;
    int performance;
};

bool _sort(Computer cmp1, Computer cmp2)
{
    if (cmp1.performance == cmp2.performance)
        return cmp1.name < cmp2.name;
    return cmp1.performance > cmp2.performance;
}

int main()
{
    int N;
    cin >> N;

    vector<Computer> computers(N);

    for (int a = 0; a < N; ++a)
    {
        string name;
        cin >> name;

        int R, S, D;
        cin >> R >> S >> D;

        computers[a].name = name;
        computers[a].performance = 2 * R + 3 * S + D;
    }

    if (computers.size() == 0)
    {
        return 0;
    }
    if (computers.size() == 1)
    {
        cout << computers[0].name;
        return 0;
    }

    sort(computers.begin(), computers.end(), _sort);

    cout << computers[0].name << '\n' << computers[1].name;
}
