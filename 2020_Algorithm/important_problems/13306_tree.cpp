#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, Q, num, x, b, c, d;
class Edge
{
public:
    int sonNode;
    int parentNode;

    Edge(int start, int p) : sonNode(start), parentNode(p){};
};

stack<int> ThisIsMyAnswer;
vector<int> parent;
vector<Edge> EdgeContainer;
int Question[400'001][3];

int Find(int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = Find(parent[node]); // path compression
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a < b)
    {
        parent[b] = a;
    }
    else if (a > b)
    {
        parent[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    EdgeContainer.push_back(Edge(0, 0)); //EdgeContainer[0] 그냥 채워넣기
    EdgeContainer.push_back(Edge(1, 1)); //EdgeContainer[1] 채워넣기

    for (int i = 1; i <= N - 1; i++)
    {
        cin >> num;

        EdgeContainer.push_back(Edge(i + 1, num)); //{son, parent} 순으로!
    }

    for (int i = 1; i <= (N - 1) + Q; i++)
    {
        cin >> x;

        if (x == 1) //연결여부 묻는지
        {
            cin >> c >> d;
            Question[i][1] = c;
            Question[i][2] = d;
        }
        else //자르는 건지
        {
            cin >> b;
            Question[i][1] = b;
            Question[i][2] = 0;
        }
    }

    for (int i = (N - 1) + Q; i >= 1; i--) //뒤에서부터 명령 수행
    {
        if (Question[i][2] == 0) //자르는 명령이면
        {
            Union(Question[i][1], EdgeContainer[Question[i][1]].parentNode);
        }
        else
        {
            if (Find(Question[i][1]) != Find(Question[i][2]))
            {
                ThisIsMyAnswer.push(0);
            }
            else
            {
                ThisIsMyAnswer.push(1);
            }
        }
    }
    while (!ThisIsMyAnswer.empty())
    {
        if (ThisIsMyAnswer.top() == 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        ThisIsMyAnswer.pop();
    }
}