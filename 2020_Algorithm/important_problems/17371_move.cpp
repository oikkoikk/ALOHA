/*
[그리디 알고리즘]

문제에 대한 실마리는 (2/3,1/3)이 (0,1)과 가장 가깝고 (4,-3)과 가장 멀다는 것이다.
이는 (0,1)과 (4,-3)을 잇는 선분 위에 존재하고 있고 점을 옮겨도 거리의 합이 달라지지 않는다.
그렇다면 답은 (0,1)이 될 수 있다.
이를 확장해서 임의의 '두 점을 잇는 선분 위에 답이 존재'할 수 있다.
1. 한 점에서 다른 모든 점까지의 거리의 최대값을 구한다.
2. 그 최대값이 최소인 점이 거리의 합의 최소가 될 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, xCor, yCor;
int minIdx = -1, minDist = 987654321;
vector<pair<int, int>> CVS;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> xCor >> yCor;

        CVS.push_back({xCor, yCor});
    }

    for (int i = 0; i < N; i++)
    {
        auto now = CVS[i];
        int maxDist = -1;

        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                auto pos = CVS[j];
                int dx = now.first - pos.first;
                int dy = now.second - pos.second;

                maxDist = max(maxDist, dx * dx + dy * dy);
            }
        }
        if (maxDist < minDist)
        {
            minDist = maxDist;
            minIdx = i;
        }
    }
    cout << (double)CVS[minIdx].first << ' ' << (double)CVS[minIdx].second;

    return 0;
}