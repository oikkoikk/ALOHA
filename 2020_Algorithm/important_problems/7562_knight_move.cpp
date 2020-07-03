#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int T, L, nowX, nowY, aimX, aimY;
int visited[300][300];
int check[300][300];
int dir[8][2] = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};//모든 움직임의 수
bool isInside(int a, int b) //체스판 안에 있니?
{
    return (a >= 0 && a < L) && (b >= 0 && b < L);
}
int BFS(pair<int,int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.second][start.first] = 1;
    check[start.second][start.first] = 0;

    while(!q.empty())
    {
        pair <int,int> curr = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nextX = curr.first + dir[i][0];
            int nextY = curr.second + dir[i][1];

            if (isInside(nextX, nextY) && visited[nextY][nextX] == 0)
            {
                q.push(pair<int, int>(nextX, nextY));
                visited[nextY][nextX] = 1;
                check[nextY][nextX] = check[curr.second][curr.first] + 1; //몇 번째 움직임인지 체크
                if (nextX == aimX && nextY == aimY)
                {
                    return check[nextY][nextX];
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0; i<T; i++)
    {
        memset(visited, 0, sizeof(visited));
        memset(check, 0, sizeof(check));
        cin >> L >> nowX >> nowY >> aimX >> aimY;

        cout << BFS(pair<int,int> (nowX,nowY)) << '\n';
    }
}