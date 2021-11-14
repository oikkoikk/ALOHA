//다이나믹 프로그래밍!
#include <iostream>

using namespace std;

int N;
int ans = __INT_MAX__;
int color[1000][3];
int DP[1000][3];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> color[i][j];
        }
    }

    DP[0][0] = color[0][0];
    DP[0][1] = color[0][1];
    DP[0][2] = color[0][2];

    for (int i = 1; i < N; i++)
    {
        //R을 선택하는 경우, G를 선택하는 경우, B를 선택하는 경우
        //모두 계산!
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + color[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + color[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + color[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        if (DP[N - 1][i] < ans)
        {
            ans = DP[N - 1][i];
        }
    }

    cout << ans;

    return 0;
}