//1 - v1 - v2 - N 경로와  1 - v2 - v1 - N 경로 비교해주면 된다!
//3번의 다익스트라로 구한다음, 최단 거리를 더해주어야한다(한 번 지나간 경로를 다시 지나갈 수 있으므로)
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> Node[20001];
int N, E, a, b, c, v1, v2, minDist;
int totalDist[2]; //거리의 합 저장 (1-v1-v2-N , 1-v2-v1-N 비교!)

void Dijkstra(int start, int end, int idx)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<int> dist(801, INF); //거리 저장하는 배열(INF로 초기화)
    dist[start] = 0;
    PQ.push({0, start});

    while (!PQ.empty())
    {
        int nowDist = PQ.top().first;
        int nowNode = PQ.top().second;
        PQ.pop();

        if (nowDist > dist[nowNode]) //최단 거리가 아니면 그냥 패스!
        {
            continue;
        }
        if (nowNode == end) //목적지까지 도착했다면, break!
        {
            break;
        }
        for (pair<int, int> p : Node[nowNode])
        {
            int nextNode = p.first;
            int nextDist = p.second + dist[nowNode];

            if (nextDist < dist[nextNode])
            {
                dist[nextNode] = nextDist;
                PQ.push({nextDist, nextNode});
            }
        }
    }
    if (dist[end] != INF)
        totalDist[idx] += dist[end]; //목적지까지의 최단 거리를 totalDist에 저장!
    else
    {
        cout << -1;
        exit(0);
    }
}
int main()
{
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;

        Node[a].push_back({b, c});
        Node[b].push_back({a, c}); //양방향이므로!
    }
    cin >> v1 >> v2; //반드시 거쳐야하는 노드

    //1-v1-v2-N
    Dijkstra(v1, v2, 0); //반드시 거쳐야하는 노드 먼저 최단경로로 이어준다.
    Dijkstra(1, v1, 0);
    Dijkstra(v2, N, 0);
    //1-v2-v1-N
    Dijkstra(v2, v1, 1); //반드시 거쳐야하는 노드 먼저 최단경로로 이어준다.
    Dijkstra(1, v2, 1);
    Dijkstra(v1, N, 1);

    minDist = (totalDist[0] < totalDist[1]) ? totalDist[0] : totalDist[1];

    cout << minDist;

    return 0;
}