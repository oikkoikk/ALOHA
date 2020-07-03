//분할정복으로 경로 추적!!
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF = INT_MAX;
const int MAX_NUMBER = 101;
long long Node[MAX_NUMBER][MAX_NUMBER]; //노드 연결 확인 + 최단거리 저장
int via[MAX_NUMBER][MAX_NUMBER];        //경유지 저장
int N, M, a, b, c;

void Backtrack(int start, int end, vector<int> &path)
{
    if (via[start][end] == 0) //경유지 없이 가면
    {
        path.push_back(start); //경로 저장
        path.push_back(end);
    }
    else
    {
        Backtrack(start, via[start][end], path);
        path.pop_back(); //경로 중복 저장 방지!
        Backtrack(via[start][end], end, path);
    }
}
void FloydWarshall()
{
    for (int k = 1; k <= N; k++) //k번 노드를 거칠 때
    {
        for (int i = 1; i <= N; i++) //i에서
        {
            for (int j = 1; j <= N; j++) //j까지
            {
                if (Node[i][j] > (Node[i][k] + Node[k][j]))
                {
                    via[i][j] = k;
                    Node[i][j] = min(Node[i][j], (Node[i][k] + Node[k][j]));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i != j)
                Node[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        if (Node[a][b] > c) //동일한 노선 중 최소값만 저장
            Node[a][b] = c;
    }

    FloydWarshall();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (Node[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << Node[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                cout << 0 << '\n';
            else
            {
                vector<int> path;

                Backtrack(i, j, path);
                cout << path.size() << ' ';
                for (int i = 0; i < path.size(); i++)
                {
                    cout << path[i] << ' ';
                }
                cout << '\n';
            }
        }
    }
}