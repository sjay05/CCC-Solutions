/*
 * Author: DynamicSquid
 */

#include <iostream>
using namespace std;

bool palindrome(string& S) {
	for (int a = 0; a < (int)S.length() / 2; ++a) {
		if (S[a] != S[S.length() - a - 1])
			return false;
	}

	return true;
}

int main() {
	string S;
	cin >> S;

	int longest = 1;
	for (int a = 2; a <= (int)S.length(); ++a) {
		for (int b = 0; b <= (int)S.length() - a; ++b) {
			string sub = S.substr(b, a);
			if (palindrome(sub) && (int)sub.length() > longest)
				longest = sub.length();
		}
	}

	cout << longest;
}
