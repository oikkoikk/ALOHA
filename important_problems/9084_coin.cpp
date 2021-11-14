//9084 동전
#include <iostream>
#include <vector>

using namespace std;

int T, N, K, selectedCoin;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<int> coin(N + 1); //동전의 가치 저장

        for (int i = 1; i <= N; i++)
        {
            cin >> coin[i];
        }

        cin >> K;

        vector<int> DP(K + 1, 0); //DP[idx] = idx를 만드는 경우의 수
        DP[0] = 1;                //초기화 작업

        for (int coinIdx = 1; coinIdx <= N; coinIdx++)
        {
            selectedCoin = coin[coinIdx];

            for (int j = selectedCoin; j <= K; j++)
            {
                DP[j] += DP[j - selectedCoin]; //j원을 만드려면, (j-selectedCoin)원에서 동전 1개를 추가하면 된다.
            }
        }

        cout << DP[K] << '\n';
    }

    return 0;
}