/*
 * Author: DynamicSquid
 */

#include <iostream>
using namespace std;

int main() {
	int D;
	cin >> D;

	int repeat = D / 1440;
	D %= 1440;
	
	int t = 1200, ans = 0;
	for (int a = 0; a < D; ++a) {
		t++;

		if (t % 100 == 60)
			t = (t + 100) / 100 * 100;
		if (t / 100 == 13)
			t = (t % 100) + 100;

		int d1 = t % 10;
		int d2 = (t / 10) % 10;
		int d3 = (t / 100) % 10;
		int d4 = t / 1000;

		if (d4 != 0 && d4 - d3 == d3 - d2 && d3 - d2 == d2 - d1)
			ans++;
		else if (d4 == 0 && d3 - d2 == d2 - d1)
			ans++;
	}

	cout << ans + (repeat * 62);
}
