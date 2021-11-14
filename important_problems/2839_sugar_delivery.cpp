#include <iostream>

using namespace std;

int N, kilFive, kilThree;
const int MAX = 5001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    kilThree = MAX, kilFive = MAX;
    for (int x = 0; x <= N / 5 + 1; x++) //적당히 큰 범위로!
    {
        for (int y = 0; y <= N / 3 + 1; y++)
        {
            if (5 * x + 3 * y == N) //5x + 3y = N가 맞을 때,
            {
                if (kilFive + kilThree > x + y) //봉지를 더 적게 사용할 수 있다면,
                {
                    kilFive = x; //갱신!
                    kilThree = y;
                }
            }
        }
    }
    if (kilThree == MAX || kilFive == MAX)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout << kilFive + kilThree;
        return 0;
    }
}