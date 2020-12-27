#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int T;
    cin >> T;

    deque<char> output;

    for (int a = 0; a < T; ++a)
    {
        int N;
        cin >> N;

        deque<int> cars;

        for (int b = 0; b < N; ++b)
        {
            int num;
            cin >> num;

            cars.push_front(num);
        }

        deque<int> branch;

        int curr = 1;

        for (int b = 0; b < cars.size(); ++b)
        {
            if (cars[b] == curr)
            {
                curr += 1;
            }
            else if (!branch.empty() && branch.front() == curr)
            {
                branch.pop_front();
                curr += 1;
                b -= 1;
            }
            else
            {
                branch.push_front(cars[b]);
            }
        }

        for (int b = 0; b < branch.size(); ++b)
        {
            if (branch[b] == curr)
                curr += 1;
        }

        if (curr - 1 != N)
            output.push_back('N');
        else
            output.push_back('Y');
    }

    for (int a = 0; a < output.size(); ++a)
        cout << output[a] << '\n';
}
