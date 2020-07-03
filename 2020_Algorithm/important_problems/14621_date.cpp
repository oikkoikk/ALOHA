//(인하대) 나만 안되는 연애
//Kruskal 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

const int MAX = 1000;
vector<pair<int, pair<int, int>>> edge; //priority queue 대신 vector로 구현할 수도 있다!
vector<int> parent(MAX + 1);
int N, M, startNode, endNode, weight;
vector<char> sex; //남초 여초 구분
long long ans;

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
            if (sex[nowEdge.second.first] != sex[nowEdge.second.second]) //성별이 다른지 확인!
            {
                Union(nowEdge.second.first, nowEdge.second.second);
                ans += nowEdge.first;
            }
            else
            {
                continue;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (parent[1] != Find(i))
        {
            cout << -1;
            return;
        }
    }
    cout << ans;
}
int main()
{
    cin >> N >> M;

    sex.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;

        sex[i] = c;
    }

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

    return 0;
}