/*
 * Author: DynamicSquid
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> nums[10005];
bool reach[10005] = { true, false };

void can_reach(int i) {
	for (int num : nums[i]) {
		if (reach[num])
			continue;

		reach[num] = true;
		can_reach(num);
	}
}

int main() {
	int N;
	cin >> N;

	for (int a = 0; a < N; ++a) {
		int M;
		cin >> M;

		nums[a].resize(M);
		for (int b = 0; b < M; ++b) {
			int num;
			cin >> num;
			nums[a][b] = num - 1;
		}
	}

	can_reach(0);

	bool reachable = true;
	for (int a = 0; a < N && reachable; ++a) {
		if (!reach[a])
			reachable = false;
	}

	cout << (reachable ? 'Y' : 'N') << '\n';

	queue<vector<int> > q;
	q.push({ 0, 1 });

	while (!q.empty()) {
		int i = q.front()[0];
		int s = q.front()[1];
		q.pop();

		if (nums[i].empty()) {
			cout << s;
			break;
		}

		for (int num : nums[i])
			q.push({ num, s + 1 });
	}
}
