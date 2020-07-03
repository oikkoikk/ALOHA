//7576 토마토 문제의 3D 버전!
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N, H, day;
int tomatoZero;
int tomato[100][100][100]; //H까지 반영!
queue<pair<pair<int, int>, int>> Q;
bool visited[100][100][100];
vector<pair<pair<int, int>, int>> dir = {{{1, 0}, 0}, {{-1, 0}, 0}, {{0, 1}, 0}, {{0, -1}, 0}, {{0, 0}, 1}, {{0, 0}, -1}};

bool isOk(int nextX, int nextY, int nextZ)
{
    if (tomato[nextY][nextX][nextZ] == 0)
    {
        return true;
    }
    return false;
}
bool isInMap(int nextX, int nextY, int nextZ)
{
    if ((0 <= nextX && nextX < M) && (0 <= nextY && nextY < N) && (0 <= nextZ && nextZ < H))
    {
        return true;
    }
    return false;
}
void BFS()
{
    int nowX, nowY, nowZ, nextX, nextY, nextZ;
    int currentQsize = 0;

    visited[Q.front().first.second][Q.front().first.first][Q.front().second] = true;

    while (!Q.empty())
    {
        currentQsize = Q.size();

        for (int pos = 0; pos < currentQsize; pos++) //Q의 사이즈만큼 돌아야 하루!
        {
            nowX = Q.front().first.first;
            nowY = Q.front().first.second;
            nowZ = Q.front().second;
            Q.pop();

            for (int i = 0; i < 6; i++)
            {
                nextX = nowX + dir[i].first.first;
                nextY = nowY + dir[i].first.second;
                nextZ = nowZ + dir[i].second;

                if (!visited[nextY][nextX][nextZ] && isInMap(nextX, nextY, nextZ) && isOk(nextX, nextY, nextZ))
                {
                    visited[nextY][nextX][nextZ] = true;
                    tomato[nextY][nextX][nextZ] = 1;
                    Q.push({{nextX, nextY}, nextZ});
                }
            }
        }
        day++; //하루 지난 것 체크!
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> tomato[j][k][i];

                if (tomato[j][k][i] == 1)
                {
                    Q.push({{k, j}, i}); //토마토 있는 곳이면 Q에 넣어놓는다.
                }
                else if (tomato[j][k][i] == 0)
                {
                    tomatoZero++;
                }
            }
        }
    }

    if (tomatoZero == 0) //이미 전부 익은 상태면, 0 출력 후 종료
    {
        cout << 0;
        exit(0);
    }

    BFS(); //BFS 시작!

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomato[j][k][i] == 0) //전부 체크해가면서 안 익은 토마토 존재하면, -1 출력 후 종료!
                {
                    cout << -1;
                    exit(0);
                }
            }
        }
    }

    cout << day - 1; //BFS() 빠져나오면서 day가 하루 추가되므로, 결과값에서 빼준다.

    return 0;
}