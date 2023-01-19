#include <iostream>
#include <queue>

using namespace std;

int N;
string temp;
int paint[100][100];
bool visited[100][100];
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int ans[2] = {0, 0};

void BFS(int x, int y)
{
  queue<pair<int, int>> Q;
  int color = paint[y][x];

  Q.push({x, y});
  visited[y][x] = true;

  while (!Q.empty())
  {
    int now_x = Q.front().first;
    int now_y = Q.front().second;
    int next_x, next_y;

    Q.pop();

    for (int i = 0; i < 4; i++)
    {
      next_x = now_x + dir[i][0];
      next_y = now_y + dir[i][1];
      if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
        continue;

      if (paint[next_y][next_x] == color && !visited[next_y][next_x])
      {
        visited[next_y][next_x] = true;
        Q.push({next_x, next_y});
      }
    }
  }
}
int count_area()
{
  int ans = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (!visited[i][j])
      {
        BFS(j, i);
        ans++;
      }
    }
  }
  return ans;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    for (int j = 0; j < temp.size(); j++)
    {
      paint[i][j] = (temp[j] == 'R' ? 1 : temp[j] == 'G' ? 2
                                                         : 3);
      // R:1 G:2 B:3
    }
  }

  ans[0] = count_area();

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      visited[i][j] = false;
      if (paint[i][j] == 2)
        paint[i][j] = 1;
    }
  }
  ans[1] = count_area();

  cout << ans[0] << " " << ans[1];
}
