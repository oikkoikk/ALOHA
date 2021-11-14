//성원이가 먼저 시작하므로, 루트-리프의 높이 합이 '짝수'이면
//성원이가 패배하게 된다!
//DFS로 루트-리프 높이의 총 합을 구한다.
#include <iostream>
#include <vector>

using namespace std;

int N, a, b;
int result;
bool visited[500'001];
vector<int> Node[500'001];

void DFS(int start, int height)
{
    bool isLeaf = true;
    visited[start] = true;

    for (auto next : Node[start])
    {
        if (!visited[next])
        {
            isLeaf = false;
            DFS(next, height + 1);
        }
    }
    if (isLeaf) //리프 노드라면
    {
        result += height;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;

        Node[a].push_back(b);
        Node[b].push_back(a);
    }

    DFS(1, 0); //루트에서 시작

    if (result % 2 == 0) //성원이가 지는 경우
    {
        cout << "No";
        return 0;
    }
    else
    {
        cout << "Yes";
        return 0;
    }
}