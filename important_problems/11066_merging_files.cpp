//다이나믹 프로그래밍!
//2306_유전자 문제와 비슷
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;
int T, K;
vector<int> files;
vector<int> costSum;
long long DP[501][501]; //DP[첫 장][마지막 장]

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> K;

        files.clear(); //초기화아아아아
        costSum.clear();
        files.resize(K + 1, 0);
        costSum.resize(K + 1, 0);
        for (int i = 0; i < K + 1; i++)
        {
            for (int j = 0; j < K + 1; j++)
            {
                DP[i][j] = INF;
            }
        }

        int num;
        for (int i = 1; i <= K; i++)
        {
            cin >> num;

            files[i] = num;
            DP[i][i] = 0;                      //필수!!!(INF와 비교해야 하므로)
            costSum[i] = costSum[i - 1] + num; //파일 부분합 저장
        }

        for (int len = 1; len <= K; len++)
        {
            for (int start = 1; start + len <= K; start++)
            {
                int end = start + len;

                for (int mid = start; mid < end; mid++)
                {
                    //mid로 연속된 장을 분기해서 비교
                    //costSum 벡터 이용하여 파일 합치는 비용 저장
                    DP[start][end] = min(DP[start][end], DP[start][mid] + DP[mid + 1][end] + (costSum[end] - costSum[start - 1]));
                }
            }
        }
        cout << DP[1][K] << '\n';
    }
}