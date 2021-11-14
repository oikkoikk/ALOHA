#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 50;
int graph[MAX][MAX];
queue<pair<int, int>> q;
int visited[MAX][MAX];
int T, N, M, K;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isInside(int a, int b) //graph 안에 들어있는지 체크
{
    return (a >= 0 && a < M) && (b >= 0 && b < N);
}

void BFS(pair<int, int> start)
{
    q.push(start);
    visited[start.second][start.first] = 1;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curr.second + dir[i][1]; //상하좌우 모든 가능성 체크
            int nextX = curr.first + dir[i][0];

            if (isInside(nextX, nextY) && visited[nextY][nextX] == 0 && graph[nextY][nextX] == 1)
            {
                visited[nextY][nextX] = 1;
                q.push(pair<int, int>(nextX, nextY));
            }
        }
    }
}
int nextToFind() //graph 다 돌려보면서 연결요소(?) 체크
{
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[j][i] == 1 && visited[j][i] == 0)
            {
                count++;
                BFS(pair<int, int>(i, j));
            }
        }
    }
    return count;
}

int main()
{
    pair<int, int> start = {0, 0};
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            pair<int, int> num;
            cin >> num.first >> num.second;

            graph[num.second][num.first] = 1;
        }
        cout << nextToFind() << '\n';
    }
}