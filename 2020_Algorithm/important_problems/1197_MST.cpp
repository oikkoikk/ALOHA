//Kruskal 알고리즘
//최소 스패닝 트리(MST)의 가중치를 알아낼 수 있다!
//O(Elog(V))
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10'000;
typedef pair<int, pair<int, int>> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> edge; //min heap구조를 위해 greater로!
vector<int> parent(MAX + 1);
int V, E, startNode, endNode, weight;
long long ans; //ans는 가중치 합 저장

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
    while (!edge.empty())
    {
        Edge e = edge.top();
        edge.pop();

        if (Find(e.second.first) != Find(e.second.second)) // 같은 집합이 아닌 상태라면
        {
            Union(e.second.first, e.second.second); //같은 집합으로 묶는다
            ans += e.first;
        }
    }
}
int main()
{
    cin >> V >> E;

    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        cin >> startNode >> endNode >> weight;

        edge.push({weight, {startNode, endNode}});
    }
    Kruskal();
    cout << ans;

    return 0;
}
