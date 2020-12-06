/*
 *    author:  DynamicSquid
 *    created: December 5th, 2020
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

bool match(unordered_map<char, int>& p1, unordered_map<char, int>& p2)
{
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (char ch : alpha)
    {
        if (p1[ch] != p2[ch])
            return false;
    }

    return true;
}

int main()
{
    string N, H;
    cin >> N >> H;

    unordered_map<char, int> nperm;
    for (char ch : N)
        nperm[ch]++;

    unordered_map<char, int> hperm;
    set<size_t> perms;

    for (int a = 0; a < H.length(); ++a)
    {
        hperm[H[a]]++;
        if (a >= N.length() - 1)
        {
            if (match(nperm, hperm))
            {
                hash<string> h;
                perms.insert(h(H.substr(a - N.length() + 1, N.length())));
            }

            hperm[H[a - N.length() + 1]]--;
        }
    }

    cout << perms.size();
}