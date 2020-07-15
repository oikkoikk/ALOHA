/*
 . . .
  / \
 . . .
 |   |
 . . .
  \ /
 . . .
  
  위의 그림과 같이 .을 2차원 좌표계의 x, y값이 정수인 정점, 짝대기를 개미가 이동할 수 있는 경로로 표현할 수 있다.
 따라서 2차원 배열로 육각형 모양 우리를 표현 할 수 있다.
  */
#include <iostream>
#include <stack>

using namespace std;

bool visit[44][44]; //N이 최대 22이므로 x,y좌표계는 최대 44까지 가능

int N;

/*
  direction: dfs를 호출한 이전 노드의 위치 
  0: 수직 방향
  1: 왼쪽
  2: 오른쪽
 */
int DFS(int x, int y, int depth, int direction)
{
    if (depth == N)
    {
        if (visit[x][y]) //회전을 하였다면 1반환!
            return 1;
        return 0;
    }
    //맵 안에 있는지, 방문했던 지점인지(N만큼 간 것이 아닐 때) 체크
    if (x < 0 || y < 0 || x > 43 || y > 43 || visit[x][y])
        return 0;

    int ans = 0;
    visit[x][y] = true;
    depth++;
    //바로 이전에 방문한 위치는 탐색하지 않아야한다.
    //direction prameter를 통해 직전에 방문한 위치를 저장한다.
    if (y % 2 == 0) //현재 |지점에 있다면
    {
        switch (direction)
        {
        case 0:
            ans = DFS(x + 1, y - 1, depth, 1) + DFS(x - 1, y - 1, depth, 2);
            break;
        case 1:
            ans = DFS(x + 1, y - 1, depth, 1) + DFS(x, y + 1, depth, 0);
            break;
        case 2:
            ans = DFS(x - 1, y - 1, depth, 2) + DFS(x, y + 1, depth, 0);
            break;
        }
    }
    else // 현재 V자 갈림길에 있다면
    {
        switch (direction)
        {
        case 0:
            ans = DFS(x + 1, y + 1, depth, 1) + DFS(x - 1, y + 1, depth, 2);
            break;
        case 1:
            ans = DFS(x + 1, y + 1, depth, 1) + DFS(x, y - 1, depth, 0);
            break;
        case 2:
            ans = DFS(x - 1, y + 1, depth, 2) + DFS(x, y - 1, depth, 0);
            break;
        }
    }

    visit[x][y] = false; //backtracking

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    visit[21][20] = true; //처음 시작하는 지점

    cin >> N;
    cout << DFS(21, 21, 0, 0); // 북쪽으로 한번 움직인다.
}