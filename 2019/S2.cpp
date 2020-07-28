#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    for (int a = 2; a <= sqrt(num); ++a)
    {
        if (num % a == 0)
            return false;
    }

    return true;
}

int main()
{
    int times;
    cin >> times;

    stringstream result;

    for (int a = 0; a < times; ++a)
    {
        int num;
        cin >> num;
        num *= 2;
        
        for (int b = 3; b <= num / 2; b += 2)
        {
            if (!isPrime(b) || !isPrime(num - b))
                continue;
            
            result << b << ' ' << num - b << '\n';
            break;
        }
    }

    cout << result.str();
}
