/* CCC 2011 Senior 2: Sum Game
 * author: DynamicSquid
 */
 
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<char> questions(N);
    vector<char> answers(N);

    for (int a = 0; a < N; ++a)
    {
        char choice;
        cin >> choice;
        questions[a] = choice;
    }

    for (int a = 0; a < N; ++a)
    {
        char choice;
        cin >> choice;
        answers[a] = choice;
    }

    int wrong = 0;
    for (int a = 0; a < questions.size(); ++a)
    {
        if (questions[a] != answers[a])
            wrong += 1;
    }

    cout << N - wrong;
}
