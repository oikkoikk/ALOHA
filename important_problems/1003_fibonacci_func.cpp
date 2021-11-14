#include <iostream>

using namespace std;

int T, N;
int DP[41] = {0, 1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 3; i <= 41; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2]; //피보나치 구현
        //0의 출력 횟수는 DP[N-1], 1의 출력 횟수는 dp[N]이다!
    }
    cin >> T;

    while (T--)
    {
        cin >> N;
        if (N == 0)
            cout << "1 0" << '\n'; //DP[-1] 방지!
        else
        {
            cout << DP[N - 1] << ' ' << DP[N] << '\n';
        }
    }
}