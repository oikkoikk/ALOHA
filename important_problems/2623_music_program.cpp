//queue를 이용한 위상정렬 + 최적화 과정까지!
//N번 돌지 못했는데, queue가 비어버리면? -> 위상정렬 불가!

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, ideas, A, B;
vector<int> Node[1001];
vector<int> Indegree(1001, 0);
vector<int> ans;
queue<int> QQ;

void topoSorting()
{
    int cnt = 0;

    while (!QQ.empty())
    {
        cnt++;
        int curr = QQ.front();
        QQ.pop();

        ans.push_back(curr);
        for (auto next : Node[curr])
        {
            Indegree[next] -= 1;     //현재 노드 제거 및 진출 간선 제거!
            if (Indegree[next] == 0) // 연결된 다음 노드가, 진입 간선 없으면 큐에 추가!
            {
                QQ.push(next);
            }
        }
        if(QQ.empty()&&cnt < N) //위상정렬이 불가능한 조건!
        {
            cout << 0;
            exit(0);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> ideas;
        cin >> A;
        for (int j = 0; j < ideas - 1; j++)
        {
            cin >> B;
            Node[A].push_back(B);
            A = B;
            Indegree[B]++; //진입 간선 갯수 체크!(최적화)
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (Indegree[i] == 0) //진입 간선 없으면 큐에 추가!
        {
            QQ.push(i);
        }
    }

    topoSorting();

    for (int data : ans)
    {
        cout << data << '\n';
    }
}