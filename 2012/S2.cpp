/* CCC 2012 Senior 2: Aromatic Numbers
 * author: DynamicSquid
 */
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    char roman[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    int numbers[] = { 1, 5, 10, 50, 100, 500, 1000 };

    string expr;
    cin >> expr;

    int sum = 0;

    for (int a = 0; a < expr.length(); a += 2)
    {
        for (int b = 0; b < 7; ++b)
        {
            if (expr[a + 1] == roman[b])
            {

                if (a < expr.length() - 2)
                {
                    for (int c = 0; c < 7; ++c)
                    {
                        if (expr[a + 3] == roman[c])
                        {
                            if (b < c)
                                sum -= ((expr[a] - '0') * numbers[b]) * 2;
                            break;
                        }
                    }
                }

                sum += (expr[a] - '0') * numbers[b];
            }
        }
    }

    cout << sum;
}
