#include <iostream>
#include <string>
using namespace std;

int maxC = 0;
int R, C;
string history = "";
const int MAX = 20;
char solution[MAX][MAX];
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
bool isInMap(int nextX, int nextY)
{
    if (0 <= nextX && nextX < C && 0 <= nextY && nextY < R)
        return true;
    return false;
}

bool isOK(int nextX, int nextY)
{
    if (history.find(solution[nextY][nextX]) != -1)
        return false;
    return true;
}
void Backtracking(int count, int nowX, int nowY)
{
    if (count > maxC)
        maxC = count;

    for (int i = 0; i < 4; i++)
    {
        int nextX = nowX + dir[i][0];
        int nextY = nowY + dir[i][1];

        if (isInMap(nextX, nextY) && isOK(nextX, nextY))
        {
            history += solution[nextY][nextX];
            Backtracking(count + 1, nextX, nextY);
            history.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nowX = 0;
    int nowY = 0;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> solution[i][j];
        }
    }
    history += solution[0][0];
    Backtracking(1, nowX, nowY);

    cout << maxC;
}