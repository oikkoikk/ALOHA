#include <iostream>
#include <queue>
#include <string.h>
int T, W, H;
using namespace std;

char map[1000][1000];
vector <pair<int,int>> fire;
bool visited[1000][1000];
int time[1000][1000];
int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool nextFire(int nextX, int nextY)
{
    for (int i = 0; i < 4; i++)
    {
        if (map[nextY+dir[i][1]][nextX+dir[i][0]] == '*') //다음에 불이 붙을 예정인 곳이면
            return true;
    }
    return false;
}

bool isInMap(int nextX, int nextY)
{
    if(0<=nextX && nextX <W && 0<=nextY && nextY < H)
        return true;
    return false;
}
void BFS(pair<int,int> start)
{
    queue<pair<int,int>> q;
    queue<pair<int,int>> qFire;

    q.push(start);
    for(int i=0; i<fire.size(); i++)
        {
            qFire.push(fire[i]);
        }
    visited[start.second][start.first] = true;
    time[start.second][start.first] = 1;
    while (!q.empty())
    {
        int currsizeQ = q.size();
        for (int i = 0; i < currsizeQ; i++)
        {

            int nowX = q.front().first;
            int nowY = q.front().second;
            q.pop();

            if (nowX == 0 || nowY == 0 || nowX == W - 1 || nowY == H - 1)
            {
                cout << time[nowY][nowX] << '\n';
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                int nextX = nowX + dir[i][0];
                int nextY = nowY + dir[i][1];

                if (map[nextY][nextX] == '.' && (!nextFire(nextX,nextY)) && isInMap(nextX, nextY) && visited[nextY][nextX] == false)
                {
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextX, nextY));
                    time[nextY][nextX] = time[nowY][nowX] + 1;
                }
            }
        }

        int currsizeF =qFire.size();
        for(int i = 0; i<currsizeF; i++)
        {
            int nowFireX = qFire.front().first;
            int nowFireY = qFire.front().second;
            qFire.pop();

            for(int j=0; j<4; j++)
            {
                int nextFireX = nowFireX + dir[j][0];
                int nextFireY = nowFireY + dir[j][1];

                if(map[nextFireY][nextFireX] != '#' && map[nextFireY][nextFireX] != '*' && isInMap(nextFireX,nextFireY))
                {
                    map[nextFireY][nextFireX] = '*';
                    qFire.push(make_pair(nextFireX,nextFireY));
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        pair<int,int> start = make_pair(0,0);
        fire.clear();
        memset(map, ' ', sizeof(map));
        memset(visited, false, sizeof(visited));
        memset(time, 0, sizeof(time));

        cin >> W >> H;
        for(int j=0; j<H; j++)
        {
            for (int k=0; k<W; k++)
            {
                cin >> map[j][k];
                if(map[j][k] == '@')
                {
                    start = make_pair(k,j);
                }
                if(map[j][k] == '*')
                {
                    fire.push_back(make_pair(k,j));
                }
            }
        }
        
        BFS(start);

    }
    
}