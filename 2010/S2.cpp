/* CCC 2010 Senior 2: Huffman Encoding
 * author: DynamicSquid
 */
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Code
{
    char letter;
    string number;
};

int main()
{
    int N;
    cin >> N;

    vector<Code> code(N);

    for (int a = 0; a < N; ++a)
    {
        char letter;
        cin >> letter;

        string number;
        cin >> number;

        code[a].letter = letter;
        code[a].number = number;
    }

    string num;
    cin >> num;

    for (int b = 0; b < code.size(); ++b)
    {
        int pos = num.find(code[b].number);
        if (pos != string::npos && pos == 0)
        {
            cout << code[b].letter;

            for (int c = 0; c < code[b].number.length(); ++c)
                num.erase(num.begin());

            b = -1;
        }
    }
}
