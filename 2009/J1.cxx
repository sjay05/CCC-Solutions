#include <iostream>

using namespace std;

int main() {
	// preset = 91
	int a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	
	int ans = 91 + a * 1 + b * 3 + c * 1;
	cout << "The 1-3-sum is " << ans;

}
