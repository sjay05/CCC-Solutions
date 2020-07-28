#include <iostream>
#include <string>

using namespace std;

int main()
{
    string flips;
    cin >> flips;

    int H = 0, V = 0;
    for (int a = 0; a < flips.length(); ++a)
    {
        if (flips[a] == 'H')
            H += 1;
        else
            V += 1;
    }

    H %= 2;
    V %= 2;

    if (H == 0 && V == 0)
        cout << "1 2\n3 4";
    else if (V == 1 && H == 0)
        cout << "2 1\n4 3";
    else if (H == 1 && V == 0)
        cout << "3 4\n1 2";
    else
        cout << "4 3\n2 1";
}
