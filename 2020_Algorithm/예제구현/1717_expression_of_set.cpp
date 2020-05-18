//Disjoint-set 알고리즘
//Find(+Path Compression) + Union
#include <iostream>
#include <vector>
using namespace std;

int N, M, flag, a, b;
vector<int> parent;

int Find(int node) //Find 연산
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = Find(parent[node]); // Path Compression!
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 0; i <= N; i++)
    {
        parent[i] = i; //초기화 작업
    }
    for (int i = 0; i < M; i++)
    {
        cin >> flag >> a >> b;

        if (flag == 0) //집합 합치기(Union)
        {
            a = Find(a);
            b = Find(b);
            if (a > b) //Union 연산
            {
                parent[a] = b; //작은 게 부모가 되도록 합친다
            }
            else if (a < b)
            {
                parent[b] = a;
            }
        }

        else if (flag == 1) //같은 집합에 포함되는지 확인(Find)
        {
            a = Find(a);
            b = Find(b);

            if (a == b)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
}