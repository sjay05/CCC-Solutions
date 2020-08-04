"""
author: DynamicSquid
"""

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<int> > grid(N);
	for (int a = 0; a < N; ++a)
	{
		for (int b = 0; b < N; ++b)
		{
			int val;
			cin >> val;

			grid[a].push_back(val);
		}
	}

	if (grid[0][0] < grid[0][1] && grid[0][0] < grid[1][0])
	{
		for (int a = 0; a < N; ++a)
		{
			for (int b = 0; b < N; ++b)
				std::cout << grid[a][b] << ' ';
			std::cout << '\n';
		}
	}
	else if (grid[0][0] > grid[0][1] && grid[0][0] < grid[1][0])
	{
		for (int a = N - 1; a >= 0; --a)
		{
			for (int b = 0; b < N; ++b)
				std::cout << grid[b][a] << ' ';
			std::cout << '\n';
		}
	}
	else if (grid[0][0] > grid[0][1] && grid[0][0] > grid[1][0])
	{
		for (int a = N - 1; a >= 0; --a)
		{
			for (int b = N - 1; b >= 0; --b)
				std::cout << grid[a][b] << ' ';
			std::cout << '\n';
		}
	}
	else
	{
		for (int a = 0; a < N; ++a)
		{
			for (int b = N - 1; b >= 0; --b)
				std::cout << grid[b][a] << ' ';
			std::cout << '\n';
		}
	}
}
