#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string.h>

const int MAX = 501;
const int INF = INT_MAX;

using namespace std;
int n, m, s, e;
int dist[MAX];

void Dijkstra(vector<pair<int, int>> Map[], bool (*visit)[MAX])
{
    for (int i = 0; i < n; ++i) //초기화 작업
        dist[i] = INF;

    dist[s] = 0;
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, s});

    while (!PQ.empty())
    {
        int nowDist = -PQ.top().first;
        int now = PQ.top().second;
        PQ.pop();

        if (dist[now] < nowDist)
            continue;

        for (auto p : Map[now])
        {
            int next = p.first;
            int nextDist = p.second + dist[now];

            if (visit[now][next]) //erase 당한 노드라면 우회!
                continue;

            if (dist[next] > nextDist)
            {
                dist[next] = nextDist;
                PQ.push({-nextDist, next});
            }
        }
    }
}

void eraseNode(vector<pair<int, int>> MapRe[], bool (*visit)[MAX])
{
    queue<int> q;
    q.push(e);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == s)
            continue;

        for (pair<int, int> p : MapRe[now])
        {
            int beforeNode = p.first;

            if (dist[beforeNode] + p.second == dist[now]) //거꾸로 가면서 최단경로가 맞으면 visited 표시!
            {
                visit[beforeNode][now] = true;
                q.push(beforeNode);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        cin >> s >> e;

        vector<pair<int, int>> Map[MAX];
        vector<pair<int, int>> MapRe[MAX]; //erase할 때 필요한 리버스 버전!

        bool visit[MAX][MAX]; //2차원으로 [출발][도착]으로 관리해야, 최단경로가 S->D인 케이스를 대비할 수 있음!
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < m; ++i)
        {
            int u, v, p;
            cin >> u >> v >> p;

            Map[u].push_back({v, p});
            MapRe[v].push_back({u, p}); //리버스에는 거꾸로 넣어준다
        }

        Dijkstra(Map, visit);
        eraseNode(MapRe, visit);
        Dijkstra(Map, visit);

        if (dist[e] != INF)
            cout << dist[e] << '\n';
        else
            cout << "-1" << '\n';
    }

    return 0;
}