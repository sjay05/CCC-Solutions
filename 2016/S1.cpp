/* CCC 2016 Senior 1: Ragaman
 * author: DynamicSquid
 *
 * First, a linear search is done on both words counting
 * the occurrence of each character. Then another linear
 * search is done on the occurrences of each letter in
 * each word, and if the difference is equal to the number
 * of wild cards, then the two words are the same.
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int letters1[26] = { 0 };
    int letters2[26] = { 0 };

    int wild = 0;
    for (int a = 0; a < (int) str1.length(); ++a)
    {
        if (str2[a] == '*')
            wild += 1;
        else
            letters2[str2[a] - 'a'] += 1;

        letters1[str1[a] - 'a'] += 1;
    }

    int wrong = 0;
    for (int a = 0; a < 26; ++a)
        wrong += abs(letters1[a] - letters2[a]);

    if (wrong != wild)
        cout << "N";
    else
        cout << "A";
}
