//0-1 Knapsack
//인덱스 조심
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int N, W; //N : 물건의 개수 , W : 배낭의 크기
    cin >> N >> W;

    const int N_MAX = N;
    const int W_MAX = W;
    int _w[N_MAX + 1], c[N_MAX + 1]; //_w[k] : k번째 물건의 무게
                                     //c[k] : k번째 물건의 가치
    int DP[N_MAX + 1][W_MAX + 1];

    memset(_w, 0, sizeof(_w));
    memset(c, 0, sizeof(c));
    memset(DP, 0, sizeof(DP));

    for (int i = 1; i <= N; i++)
    {
        cin >> _w[i] >> c[i];
    }

    for (int k = 0; k < N; k++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (w >= _w[k + 1])
            {
                DP[k + 1][w] = max(DP[k][w], DP[k][w - _w[k + 1]] + c[k + 1]);
            }
            else //w-_w[k+1] <0 일 때
            {
                DP[k + 1][w] = DP[k][w];
            }
        }
    }

    cout << DP[N_MAX][W_MAX];
}