//0-1 Knapsack
//보석의 무게 = 체력 , 보석의 가치 = 기쁨!
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int N, W = 99; //N : 보석의 개수 , W : 배낭의 크기
    cin >> N;

    const int N_MAX = N;
    const int W_MAX = 99;
    int _w[N_MAX + 1], c[N_MAX + 1]; //_w[k] : k번째 보석의 무게
                                     //c[k] : k번째 보석의 가치
    int DP[N_MAX + 1][W_MAX + 1];

    memset(DP, 0, sizeof(DP));

    for (int i = 1; i <= N; i++)
    {
        cin >> _w[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
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