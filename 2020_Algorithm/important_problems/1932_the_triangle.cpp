//다이나믹 프로그래밍!
#include <iostream>
#include <vector>

using namespace std;

int N, temp, ans;
vector<int> numTree[501];
int DP[501][501]; //DP[x층][y번째]

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> temp;
            numTree[i].push_back(temp);
        }
    }
    DP[1][1] = numTree[1][0];

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (1 < j && j < i) //중간 부분
            {
                //두 경우를 비교하여 저장
                DP[i][j] = max(DP[i - 1][j - 1] + numTree[i][j - 1], DP[i - 1][j] + numTree[i][j - 1]);
            }
            else //양쪽 모서리 부분
            {
                if (j == 1) //'/'방향
                    DP[i][j] = DP[i - 1][1] + numTree[i][0];
                else // '\' 방향
                    DP[i][j] = DP[i - 1][i - 1] + numTree[i][i - 1];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (ans < DP[N][i])
            ans = DP[N][i];
    }

    cout << ans;
}