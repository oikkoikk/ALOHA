#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N, Mint;
double M;
int num1, num2Int;
double num2;
int DP[10001]; //DP[idx]는 idx원일 때, 얻을 수 있는 최대 칼로리

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second; //가격 낮은게 먼저 오도록
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0.00)
            break;

        vector<pair<int, int>> candy; //{칼로리, 돈}

        memset(DP, 0, sizeof(DP));

        Mint = (int)(M * 100 + 0.5);
        for (int i = 1; i <= N; i++)
        {
            cin >> num1 >> num2;

            num2Int = (int)(num2 * 100 + 0.5);
            candy.push_back({num1, num2Int});
        }

        sort(candy.begin(), candy.end(), comp);
        // DP 갱신
        for (int i = 0; i < N; i++)
        {
            for (int j = candy[i].second; j <= Mint; j++) //동전 각각의 금액부터 M까지!
            {
                DP[j] = max(DP[j], DP[j - candy[i].second] + candy[i].first); // 원래 있는 대로 할지, 동전 바꿀지 결정
            }
        }
        cout << DP[Mint] << '\n';
    }

    return 0;
}