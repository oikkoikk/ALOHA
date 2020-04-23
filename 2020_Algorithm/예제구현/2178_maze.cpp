#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100;
int graph[MAX+1][MAX+1];
queue<pair<int, int>> q;
int visited[MAX+1][MAX+1];
int N,M;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isInside(int a, int b) //graph 안에 들어있는지 체크
{
    return (a >= 1 && a <= N) && (b >= 1 && b <= M);
}
int BFS(pair<int, int> start)
{
    q.push(start);
    visited[start.first][start.second] = 1; //방문 체크 & 최단거리 기록

    while(!q.empty())
    {
        pair <int,int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nextY = curr.first + dir[i][0]; //상하좌우 모든 가능성 체크
            int nextX = curr.second + dir[i][1];

            if(isInside(nextY, nextX) && visited[nextY][nextX] == 0&& graph[nextY][nextX] == 1)
            {
                visited[nextY][nextX] =visited[curr.first][curr.second]+1; //최단거리 기록
                q.push(pair<int,int>(nextY, nextX));
            }
        }
        
    }

    return visited[N][M];

}
int main()
{
    pair<int, int> start = {1, 1};
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            scanf("%1d", &graph[i][j]); //한 개씩 입력받기 위해 %1d
        }
    }
    cout << BFS(start);
}