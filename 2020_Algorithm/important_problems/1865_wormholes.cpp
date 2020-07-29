//음수가중치 -> 벨만-포드!
#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int TC, N, M, W, S, E, T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TC;

    while (TC--)
    {
        bool flag = true;           // 음수 사이클 발견하면 false로!
        vector<int> dist(501, INF); //거리 저장하는 배열(INF로 초기화)
        vector<pair<int, int>> Edges[501];
        cin >> N >> M >> W;

        for (int i = 1; i <= M; i++)
        {
            cin >> S >> E >> T;                  //T는 가중치
            Edges[S].push_back(make_pair(E, T)); //도로는
            Edges[E].push_back(make_pair(S, T)); //양방향!
        }

        for (int i = 1; i <= W; i++)
        {
            cin >> S >> E >> T;
            Edges[S].push_back(make_pair(E, -T)); //웜홀은 시간이 줄어드니까 -T!
        }
        //벨만-포드
        dist[1] = 0;

        for (int i = 1; i <= N; i++) //최단 거리 Relax(N-1시도 까지!) + 음수 사이클 찾기(N번째 도는데 Relax되면 음의 사이클을 돌고 있는 것!)
        {
            for (int from = 1; from <= N; from++)
            {
                for (auto p : Edges[from])
                {
                    int to = p.first;
                    int weight = p.second;
                    //주의) 이 문제에서는 사이클의 유무만 판단하면 되므로, 아래와 같은 INF 비교를 하지 않는다!!
                    /*
                    if (dist[from] == INF) //출발지에서 가지 못하는 곳이면 패스!
                    {
                        continue;
                    }
                    반례)
                    1
                    3 2 0
                    2 3 -1
                    3 2 -1
                    */
                    if (dist[to] > dist[from] + weight)
                    {
                        if (i == N)
                        {
                            flag = false; //N번 째일 때 Relax 되면 음수 사이클!
                        }
                        dist[to] = dist[from] + weight;
                    }
                }
            }
        }
        if (flag == false)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}