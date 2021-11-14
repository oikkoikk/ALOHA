#include <iostream>
#include <set>
#include <string>

using namespace std;

int M, N;
string comm;
set<int> mySet;
set<int> exampleSet;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int j = 1; j <= 20; j++)
    {
        exampleSet.insert(j);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> comm;

        if (comm == "add")
        {
            cin >> N;
            if (mySet.find(N) != mySet.end())
                continue;
            mySet.insert(N);
        }
        else if (comm == "remove")
        {
            cin >> N;
            if (mySet.find(N) != mySet.end())
                mySet.erase(N);
        }
        else if (comm == "check")
        {
            cin >> N;
            if (mySet.find(N) != mySet.end())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (comm == "toggle")
        {
            cin >> N;
            if (mySet.find(N) != mySet.end())
            {
                mySet.erase(N);
            }
            else
            {
                mySet.insert(N);
            }
        }
        else if (comm == "all")
        {
            mySet = exampleSet;
        }
        else if (comm == "empty")
        {
            mySet.clear();
        }
    }
}