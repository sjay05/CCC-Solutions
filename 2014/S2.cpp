/*
 * Author: DynamicSquid
 */
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<string> students1(N);
    vector<string> students2(N);

    for (int a = 0; a < N; ++a)
    {
        string name;
        cin >> name;
        students1[a] = name;
    }

    for (int a = 0; a < N; ++a)
    {
        string name;
        cin >> name;
        students2[a] = name;
    }

    for (size_t a = 0; a < students1.size(); ++a)
    {
        if (students1[a] == students2[a])
        {
            cout << "bad";
            return 0;
        }

        string partner = students2[a];

        for (size_t b = 0; b < students1.size(); ++b)
        {
            if (students1[b] == partner && students2[b] != students1[a])
            {
                cout << "bad";
                return 0;
            }
        }
    }

    cout << "good";
}
