#include <iostream>
#include <vector>
using namespace std;

struct Cell {
    int val;
    bool visit;
};

void jump(vector<vector<Cell> >& grid, int x, int y) {
    if (x == grid[0].size() - 1 && y == grid.size() - 1)
        throw 0;

    int num = grid[y][x].val;
    grid[y][x].visit = true;

    for (int a = 1; a * a <= num; ++a) {
        if (num % a == 0) {
            int num1 = a;
            int num2 = num / a;

            if (num2 <= grid.size() && num1 <= grid[0].size() && !grid[num2 - 1][num1 - 1].visit) {
                grid[num2 - 1][num1 - 1].visit = true;
                jump(grid, num1 - 1, num2 - 1);
            }
            if (num2 <= grid[0].size() && num1 <= grid.size() && !grid[num1 - 1][num2 - 1].visit) {
                grid[num1 - 1][num2 - 1].visit = true;
                jump(grid, num2 - 1, num1 - 1);
            }
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<Cell> > grid(M);
    for (int a = 0; a < M; ++a) {
        for (int b = 0; b < N; ++b) {
            int num;
            cin >> num;
            grid[a].push_back({ num, false });
        }
    }

    grid[0][0].visit = true;

    try {
        jump(grid, 0, 0);
        cout << "no";
    }
    catch (...) {
        cout << "yes";
    }
}
