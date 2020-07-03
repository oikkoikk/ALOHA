//다익스트라 알고리즘
//최단경로!

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<int> dist(20001, INF); //거리 저장하는 배열(INF로 초기화)
vector<pair<int, int>> Node[20001];
int V, E, K, u, v, w;

void Dijkstra(int start)
{
    priority_queue<pair<int, int>> PQ;
    dist[start] = 0;
    PQ.push({0, start});

    while (!PQ.empty())
    {
        int now, nowDist;
        nowDist = -PQ.top().first;
        now = PQ.top().second;
        PQ.pop();

        if (nowDist > dist[now]) //최단 거리가 아니면 그냥 패스!
        {
            continue;
        }

        for (auto p : Node[now])
        {
            int next = p.first;
            int nextDist = p.second + dist[now];

            if (nextDist < dist[next])
            {
                dist[next] = nextDist;
                PQ.push({-nextDist, next});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;
    cin >> K;
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v >> w; //w는 가중치
        Node[u].push_back({v, w});
    }

    Dijkstra(K);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }

        else
        {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}