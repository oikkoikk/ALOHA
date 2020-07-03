#include <iostream>
#include <deque>

using namespace std;
const int MAX = 1000;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M;
int tomato[MAX][MAX];
deque<pair<int, int>> dq;
int noTomato;
//토마토가 전부 익었는지 확인
bool allRipe(void)
{
    int possible = M * N - noTomato;
    int tomatoCnt = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (tomato[i][j] == 1)
                tomatoCnt++;
    return possible == tomatoCnt;
}
int BFS(void)
{
    int day = 0;
    //처음부터 익힐 수 있는 토마토가 없는 경우
    if (dq.empty())
        return -1;
    while (!dq.empty())
    {
        int currentSize = dq.size(); //동시에 토마토들이 익을 수 있도록
        for (int i = 0; i < currentSize; i++)
        {
            int y = dq.front().first;
            int x = dq.front().second;
            for (int i = 0; i < 4; i++)
            {
                int nextY = y + dir[i][1];
                int nextX = x + dir[i][0];
                //다음 토마토가 범위 안에 있고 안 익었을 경우에만
                if (0 <= nextY && nextY < M && 0 <= nextX && nextX < N && tomato[nextY][nextX] == 0)
                {
                    tomato[nextY][nextX] = 1;
                    dq.push_back(make_pair(nextY, nextX));
                }
            }
            dq.pop_front();
            //익힐 수 있는 토마토를 전부 익혔고 전부 익었을 경우
            if (dq.size() == 0 && allRipe())
                return day;
            //익힐 수 있는 토마토는 전부 익혔지만 안 익은 토마토 존재
            else if (dq.size() == 0 && !allRipe())
                return -1;
        }
        day++;
    }
}
int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                dq.push_back(make_pair(i, j)); //익은 토마토는 덱에 넣는다
            else if (tomato[i][j] == -1)
                noTomato++; //토마토를 넣을 수 없는 칸
        }
    if (dq.size() == M * N - noTomato)
    {
        cout << 0 << endl; //모든 토마토 다 익었을 경우
    }
    else
    {
        int result = BFS();
        cout << result << endl;
    }
    return 0;
}