#include <iostream>

using namespace std;

const int INF = 987654321; //최솟값을 찾기 위해, INF로 초기화!
int N;
int DP[1'000'000 + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        DP[i] = INF;
    }

    DP[1] = 0;
    for (int i = 1; i <= N; i++) //역으로 1부터 올라가면서 경우의 수 찾기!
    {
        if (i * 3 <= N)
        {
            DP[i * 3] = min(DP[i * 3], DP[i] + 1);
        }
        if (i * 2 <= N)
        {
            DP[i * 2] = min(DP[i * 2], DP[i] + 1);
        }
        if (i + 1 <= N)
        {
            DP[i + 1] = min(DP[i + 1], DP[i] + 1);
        }
    }

    cout << DP[N];
}