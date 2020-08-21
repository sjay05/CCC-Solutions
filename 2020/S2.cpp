/* CCC 2020 Senior 2: Escape Room
 * author: DynamicSquid
 */
 
#include <iostream>
#include <vector>

using namespace std;

struct Cell
{
    int val;
    bool visit;
};

void Factor(vector<vector<Cell> >& grid, Cell& cell)
{
    if (&cell == &grid.back().back())
        throw "yes";

    for (int a = 1; a * a <= cell.val; ++a)
    {
        if (cell.val % a == 0)
        {
            if (a - 1 < grid.size() && cell.val / a - 1 < grid[a - 1].size() && !grid[a - 1][cell.val / a - 1].visit)
            {
                grid[a - 1][cell.val / a - 1].visit = true;
                Factor(grid, grid[a - 1][cell.val / a - 1]);
            }

            if (cell.val / a - 1 < grid.size() && a - 1 < grid[cell.val / a - 1].size() && !grid[cell.val / a - 1][a - 1].visit)
            {
                grid[cell.val / a - 1][a - 1].visit = true;
                Factor(grid, grid[cell.val / a - 1][a - 1]);
            }
        }
    }
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<vector<Cell> > grid(M);

    for (int a = 0; a < M; ++a)
    {
        for (int b = 0; b < N; ++b)
        {
            int num;
            cin >> num;

            grid[a].push_back(Cell{ num, false });
        }
    }

    grid[0][0].visit = true;

    try {
        Factor(grid, grid[0][0]);
        cout << "no";
    }
    catch (const char* e) {
        cout << e;
    }
}
