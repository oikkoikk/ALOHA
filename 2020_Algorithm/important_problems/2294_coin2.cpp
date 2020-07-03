// 동전 교환 2
#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> coin(N + 1, 0);
    vector<int> DP(K + 1, INF); //DP[idx]는 idx원을 만들 때 필요한 동전의 최소 개수
                                //최소 개수를 구해야하므로 INF로 초기화!
    DP[0] = 0;                  //첫 동전 초기화할 수 있도록 DP[0] = 0으로 초기화!

    for (int i = 1; i <= N; i++)
    {
        cin >> coin[i];
    }

    // DP 갱신
    // 모든 동전에 대하여 확인하고 min 으로 값을 갱신한다.
    for (int i = 1; i <= N; i++)
    {
        for (int j = coin[i]; j <= K; j++) //동전 각각의 금액부터 K까지!
        {
            DP[j] = min(DP[j], DP[j - coin[i]] + 1); // 원래 있는 대로 할지, 동전 바꿀지 결정 (j원을 만드려면, (j-coin[i])원에서 동전 1개를 추가하면 된다.)
        }
    }

    if (DP[K] == INF)
        cout << -1;
    else
    {
        cout << DP[K];
    }

    return 0;
}