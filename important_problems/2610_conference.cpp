// 플로이드-와샬 + BFS
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;
const int MAX_NUMBER = 101;
long long Node[MAX_NUMBER][MAX_NUMBER]; //노드 연결 확인 + 최단거리 저장
vector<long long> People[MAX_NUMBER];
vector<int> represent;
bool visited[MAX_NUMBER];
int N, M, a, b;

void FloydWarshall()
{
    for (int k = 1; k <= N; k++) //k번 노드를 거칠 때
    {
        for (int i = 1; i <= N; i++) //i에서
        {
            for (int j = 1; j <= N; j++) //j까지
            {
                Node[i][j] = min(Node[i][j], (Node[i][k] + Node[k][j]));
            }
        }
    }
}

void BFS(int start)
{
    vector<int> unions;
    queue<int> q;

    q.push(start);
    visited[start] = true;
    unions.push_back(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < People[now].size(); i++)
        {
            if (!visited[People[now][i]])
            {
                q.push(People[now][i]);
                unions.push_back(People[now][i]);
                visited[People[now][i]] = true;
            }
        }
    }

    int minim = 0;
    long long maxBefore = INF;
    for (int i = 0; i < unions.size(); i++)
    {
        int tempRep = unions[i];
        long long nowMax = 0;
        for (int j = 0; j < unions.size(); j++)
        {
            if (nowMax < Node[unions[j]][tempRep])
            {
                nowMax = Node[unions[j]][tempRep];
            }
        }
        if (nowMax < maxBefore)
        {
            minim = unions[i];
            maxBefore = nowMax;
        }
    }
    represent.push_back(minim);
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i != j)
                Node[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        People[a].push_back(b);
        People[b].push_back(a);
        Node[a][b] = 1;
        Node[b][a] = 1;
    }

    FloydWarshall();
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
            BFS(i);
    }
    cout << represent.size() << '\n';

    sort(represent.begin(), represent.end());

    for (int i = 0; i < represent.size(); i++)
    {
        cout << represent[i] << '\n';
    }
}