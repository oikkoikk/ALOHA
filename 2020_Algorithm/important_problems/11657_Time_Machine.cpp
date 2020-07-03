//벨만-포드 알고리즘
//음수 가중치 사용 가능
//음수 사이클 "발견" 가능
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const long long INF = LONG_LONG_MAX;

vector<long long> dist(501, INF); //거리 저장하는 배열(INF로 초기화)
vector<pair<int, int>> Edges[501];
int N, M, A, B, C;
bool flag = true; // 음수 사이클 발견하면 false로!

bool BellmanFord(int start)
{
    dist[start] = 0;

    for (int i = 1; i <= N; i++) //최단 거리 Relax(N-1시도 까지!) + 음수 사이클 찾기(N번째 도는데 Relax되면 음의 사이클을 돌고 있는 것!)
    {
        for (int from = 1; from <= N; from++)
        {
            for (auto p : Edges[from])
            {
                int to = p.first;
                int weight = p.second;

                if (dist[from] == INF) //출발지에서 가지 못하는 곳이면 패스!
                {
                    continue;
                }
                else if (dist[to] > dist[from] + weight)
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

    return flag;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A >> B >> C; //C는 가중치(0이면 순간이동, 음수이면 타임머신)
        Edges[A].push_back(make_pair(B, C));
    }

    if (BellmanFord(1))
    {
        for (int n = 2; n <= N; n++)
        {
            if (dist[n] == INF)
            {
                cout << "-1\n";
            }
            else
            {
                cout << dist[n] << '\n';
            }
        }
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}