/* CCC 2012 Senior 3: Absolutely Acidic
 * author: DynamicSquid
 */
 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Reading
{
    int number;
    int count;
};

bool SortReading(Reading rd1, Reading rd2)
{
    if (rd1.count == rd2.count)
        return rd1.number > rd2.number;
    return rd1.count > rd2.count;
}

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);

    for (int a = 0; a < N; ++a)
    {
        int num;
        cin >> num;

        nums[a] = num;
    }

    sort(nums.begin(), nums.end());

    vector<Reading> readings;

    int curr = 0;
    for (int a = 0; a < N; ++a)
    {
        if (nums[a] != curr)
        {
            readings.push_back(Reading{ nums[a], 1 });
            curr = nums[a];
        }
        else
        {
            readings.back().count += 1;
        }
    }

    sort(readings.begin(), readings.end(), SortReading);

    if (readings.front().count == readings[1].count)
    {
        for (int a = 1; a < readings.size(); ++a)
        {
            if (readings[a].count != readings[0].count)
            {
                cout << readings[0].number - readings[a - 1].number;
                return 0;
            }
        }

        cout << readings.front().number - readings.back().number;
    }
    else
    {
        for (int a = 1; a < readings.size(); ++a)
        {
            if (readings[a].count != readings[1].count)
            {
                if (readings[0].number > readings[a - 1].number)
                    cout << readings[0].number - readings[a - 1].number;
                else
                    cout << readings[1].number - readings[0].number;

                return 0;
            }
        }

        if (readings[0].number < readings[1].number)
            cout << readings[1].number - readings[0].number;
        else
            cout << readings[0].number - readings.back().number;
    }
}
