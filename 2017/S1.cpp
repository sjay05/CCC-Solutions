/*
author: DynamicSquid
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> team1(N);
	vector<int> team2(N);

	for (int a = 0; a < N; ++a)
	{
		int num;
		cin >> num;
		team1[a] = num;
	}

	for (int a = 0; a < N; ++a)
	{
		int num;
		cin >> num;
		team2[a] = num;
	}

	int K = 0;
	int score1 = 0, score2 = 0;
	for (int a = 0; a < N; ++a)
	{
		score1 += team1[a];
		score2 += team2[a];

		if (score1 == score2)
			K = a + 1;
	}

	cout << K;
}
