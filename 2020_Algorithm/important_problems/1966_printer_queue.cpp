#include <iostream>
#include <vector>

using namespace std;

int T, N, M, prior, nowPrior, nowIdx, flag;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        vector<pair<int, int>> prinQ;
        vector<pair<int, int>> resultQ;

        cin >> N >> M;

        for (int idx = 0; idx < N; idx++)
        {
            cin >> prior;
            prinQ.push_back({idx, prior});
        }
        while (!prinQ.empty())
        {
            flag = 0; //flag 초기화!
            nowIdx = prinQ.front().first;
            nowPrior = prinQ.front().second;

            for (int i = 0; i < prinQ.size(); i++)
            {
                if (nowPrior < prinQ[i].second) //중요도가 더 큰 게 있다면,
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                prinQ.push_back(prinQ.front());
                prinQ.erase(prinQ.begin());
            }
            else
            {
                resultQ.push_back(prinQ.front()); //위치가 확정된 요소는 resultQ에 넣는다!
                prinQ.erase(prinQ.begin());
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (resultQ[i].first == M)
            {
                cout << i + 1 << '\n';
            }
        }
    }
}