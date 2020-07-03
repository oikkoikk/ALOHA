//두더지가 정보섬에 올라온 이유
//가중치가 큰 순으로 Union하기!
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, X, Y, W;

vector<pair<long long, pair<long long, long long>>> Edge; //{가중치, {부모,자식}}
vector<long long> parent;
vector<long long> NodeNumber;
long long sum = 0;

long long Find(long long node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = Find(parent[node]); // path compression
}

void Union(long long a, long long b, long long pos)
{
    a = Find(a);
    b = Find(b);

    if (a < b)
    {
        parent[b] = a;
        NodeNumber[a] += (NodeNumber[b]); //개수 합치기
    }
    else if (a > b)
    {
        parent[a] = b;
        NodeNumber[b] += (NodeNumber[a]); //개수 합치기
    }
}

int main()
{
    cin >> N;

    parent.resize(N + 1);
    NodeNumber.resize(N + 1);
    fill(NodeNumber.begin(), NodeNumber.end(), 1);

    for (long long i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (long long i = 0; i < N - 1; i++)
    {
        cin >> X >> Y >> W;

        Edge.push_back({W, {X, Y}});
    }

    sort(Edge.begin(), Edge.end());

    long long pos = N - 2;

    while (pos >= 0) //가중치 큰 순으로 Union하려면 뒤에서부터!
    {
        if (Find(Edge[pos].second.first) != Find(Edge[pos].second.second))
        {
            sum += Edge[pos].first * (NodeNumber[Find(Edge[pos].second.first)]) * (NodeNumber[Find(Edge[pos].second.second)]); //개수*개수*가중치!
            Union(Edge[pos].second.first, Edge[pos].second.second, pos);
        }
        pos--;
    }

    cout << sum;
}