/**
 *    author:  sjay05
**/
#include <iostream>

using namespace std;

void check(int month, int day) {
	if (month == 2) {
		if (day == 18) cout << "Special";
		else {
			if (day < 18) cout << "Before";
			if (day > 18) cout << "After";
		}
	} else {
		if (month < 2) cout << "Before";
		if (month > 2) cout << "After";
	}
}

int main() {
	int month, day;
	cin >> month;
	cin >> day;
	check(month, day);
}
