//Union-Find!
#include <iostream>
#include <vector>
using namespace std;

int N, M, flag, routeNode;
vector<int> parent;
vector<int> route;
int start;

int Find(int node) //루트 찾아주는 Find 연산
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = Find(parent[node]); // Path Compression!
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    parent[y] = x; //작은 게 부모가 되도록
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i; //초기화 작업
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> flag;
            if (flag == 1)
            {
                if (i < j)
                {
                    Union(i, j); //작은 게 부모가 되도록 Union
                }
                else
                {
                    continue;
                }
            }
        }
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> routeNode;
        route.push_back(routeNode);
        if (i == 1)
        {
            start = routeNode;
            start = Find(start);
        }
    }
    for (int i = 1; i < route.size(); i++)
    {
        if (start != Find(route[i]))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}