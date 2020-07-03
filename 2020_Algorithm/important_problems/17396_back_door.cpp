//숭고한 백도어 문제
//long long 주의!
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const long long INF = LONG_LONG_MAX; //long long 주의!

vector<long long> dist(100001, INF); //거리 저장하는 배열(INF로 초기화)
vector<int> sight;                   //시야에 보이는지 체크하는 배열
priority_queue<pair<long long, int>> PQ;
vector<pair<int, int>> Node[100001];
int N, M, a, b, t;

void Dijkstra(int start)
{
    dist[0] = 0;
    for (int i = 0; i < Node[start].size(); i++)
    {
        //아직 안 와본 곳이고, 시야에 보이지 않으면
        if (dist[Node[start][i].first] == INF && sight[Node[start][i].first] == 0)
        {
            PQ.push({-Node[start][i].second, Node[start][i].first}); //-붙여서 가중치 작은 순으로!
        }
    }

    while (!PQ.empty())
    {
        int now;
        long long nowDist;
        nowDist = -PQ.top().first;
        now = PQ.top().second;
        PQ.pop();

        if (nowDist > dist[now]) //최단거리가 아니면 그냥 패스
        {
            continue;
        }
        dist[now] = nowDist;
        //cout << "now : " << now << '\n' << "nowDist : " << nowDist << '\n';
        for (int i = 0; i < Node[now].size(); i++)
        {
            if (dist[Node[now][i].first] == INF && sight[Node[now][i].first] == 0)
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

    cin >> N >> M;
    int num;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        sight.push_back(num);
    }
    sight[N - 1] = 0; // 마지막은 그냥 편하게 0으로 채우기

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> t; //t는 가중치
        Node[a].push_back({b, t});
        Node[b].push_back({a, t}); //연결은 양방향!
    }

    Dijkstra(0); //0번째 분기점에서 출발

    if (dist[N - 1] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << dist[N - 1];
    }
}