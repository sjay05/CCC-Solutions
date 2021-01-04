#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<string> lines;
    for (int a = 0; a < num; ++a) {
        string line;
        cin >> line;

        lines.push_back(line); 
    }

    for (size_t a = 0; a < lines.size(); ++a) {
        char letter = lines[a][0];
        int count = 0;

        for (size_t b = 0; b < lines[a].length(); ++b) {
            if (lines[a][b] == letter) {
                count++;
            }
            else {
                cout << count << ' ' << letter << ' ';

                letter = lines[a][b];
                count = 1;
            }
        }

        cout << count << ' ' << letter << '\n';
    }
}
