//MST 응용문제!
//이번에는 priority_queue 대신 vector로 구현해보았다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

const int MAX = 100'000;
vector<pair<int, pair<int, int>>> edge; //priority queue 대신 vector로 구현할 수도 있다!
vector<int> parent(MAX + 1);
int N, M, startNode, endNode, weight;
vector<long long> V; //값 저장 + 도시를 분할할 기준!(가장 가중치 큰 길만 없애면 최소 스패닝 트리가 2개 만들어진다)
long long ans;       //값 저장

int Find(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = Find(parent[node]);
}

void Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);

    if (rootX != rootY)
    {
        if (rootX < rootY)
        {
            parent[rootY] = rootX;
        }
        else if (rootY < rootX)
        {
            parent[rootX] = rootY;
        }
    }
}
void Kruskal()
{
    sort(edge.begin(), edge.end()); //가중치 기준 오름차순으로 정렬

    for (auto nowEdge : edge)
    {
        if (Find(nowEdge.second.first) != Find(nowEdge.second.second))
        {
            Union(nowEdge.second.first, nowEdge.second.second);
            V.push_back(nowEdge.first);
        }
    }
    for (int i = 0; i < V.size() - 1; i++) //최소 스패닝 트리로 짠 1개의 마을 루트는 이미 최소 상태!
                                           //거기서 가중치가 최대인 마을 1개만 독립시키면 마을은 2개가 되고, 가중치도 최소로 만들 수 있다.
    {
        ans += V[i];
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> startNode >> endNode >> weight;

        edge.push_back({weight, {startNode, endNode}});
    }
    Kruskal();
    cout << ans;

    return 0;
}