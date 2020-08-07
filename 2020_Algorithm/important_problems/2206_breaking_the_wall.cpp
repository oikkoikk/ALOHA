//벽 부술 수 있는 기회가 1번 주어짐
//조건 까다로운 BFS! visted를 3차원으로 설정해서 확인
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, temp;
int map[1001][1001];
int visited[1001][1001][2]; //이동거리 저장 + 방문 확인 + 벽 부쉈는지 체크
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isOK(int X, int Y)
{
    return (1 <= X && X <= M && 1 <= Y && Y <= N);
}
int BFS(int startX, int startY)
{
    queue<tuple<int, int, int>> Q; //pair확장판 tuple!
    visited[startY][startX][1] = 1;
    Q.push({startX, startY, 1});

    while (!Q.empty())
    {
        int nowX = get<0>(Q.front()); //tuple은 get<0>부터!
        int nowY = get<1>(Q.front());
        int punch = get<2>(Q.front());
        Q.pop();

        if (nowX == M && nowY == N)
        {
            return visited[nowY][nowX][punch];
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dir[i][0];
            int nextY = nowY + dir[i][1];

            if (isOK(nextX, nextY))
            {
                //방문 체크 하지 않음! 주의!!
                if (map[nextY][nextX] == 1 && punch == 1) //벽이 아직 있고, 부술 수 있다면
                {
                    //이렇게 하면, 다른 경로를 통해 이 벽을 부수게 되어도 문제가 생기지 않음!
                    visited[nextY][nextX][punch - 1] = visited[nowY][nowX][punch] + 1;
                    Q.push({nextX, nextY, punch - 1});
                }
                else if (map[nextY][nextX] == 0 && !visited[nextY][nextX][punch]) //벽도 없고, 방문한 적도 없는 곳이면
                {
                    visited[nextY][nextX][punch] = visited[nowY][nowX][punch] + 1;
                    Q.push({nextX, nextY, punch});
                }
            }
        }
    }
    return -1;
}
int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &map[i][j]); //1글자씩 입력해야하므로 scanf %1d 사용!
        }
    }
    cout << BFS(1, 1);
}