#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, temp, tempTwo, minNum = 987654321, minPerson;
bool Node[101][101]; //친구관계가 중복되어 들어올 수 있다는 조건에 따라, 인접행렬로!
int level[101][101];
bool visited[101];

void BFS(int start)
{
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    int relationship = 1;

    while (!Q.empty())
    {
        int queueSize = Q.size(); //단계를 계산하기 위해!
        for (int round = 0; round < queueSize; round++)
        {
            int now = Q.front();
            Q.pop();
            for (int next = 1; next <= N; next++)
            {
                if (Node[now][next] && !visited[next])
                {
                    Q.push(next);
                    visited[next] = true;
                    if (!level[start][next] && !level[next][start])
                    {
                        //이미 계산됐다면 패스!
                        level[start][next] = relationship;
                        level[next][start] = relationship;
                    }
                }
            }
        }
        relationship++;
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
        cin >> temp >> tempTwo;
        Node[temp][tempTwo] = true;
        Node[tempTwo][temp] = true;
    }
    for (int i = 1; i <= N; i++)
    {
        BFS(i);
        memset(visited, 0, sizeof(visited)); //visited 배열 초기화!
    }
    for (int i = 1; i <= N; i++)
    {
        int total = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i != j)
            {
                total += level[i][j];
            }
        }
        if (minNum > total)
        {
            minNum = total;
            minPerson = i;
        }
    }

    cout << minPerson;
}
