//다익스트라 알고리즘
//최단경로!

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<int> dist(20001, INF); //거리 저장하는 배열(INF로 초기화)
priority_queue<pair<int, int>> PQ;
vector<pair<int, int>> Node[20001];
int V, E, K, u, v, w;

void Dijkstra(int start)
{
    dist[start] = 0;

    for (int i = 0; i < Node[start].size(); i++)
    {
        if (dist[Node[start][i].first] == INF) //아직 안 와본 곳이면
        {
            PQ.push({-Node[start][i].second, Node[start][i].first}); //-붙여서 가중치 작은 순으로!
        }
    }

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
        dist[now] = nowDist;
        for (int i = 0; i < Node[now].size(); i++)
        {
            if (dist[Node[now][i].first] == INF)
            {
                PQ.push({-(nowDist + Node[now][i].second), Node[now][i].first});
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