#include <iostream>

using namespace std;

int N, white, blue;
int paper[128][128];

void divide(int x, int y, int len)
{
  for (int i = y; i < y + len; i++)
  {
    for (int j = x; j < x + len; j++)
    {
      if (paper[i][j] != paper[y][x])
      {
        divide(x, y, len / 2);
        divide(x + len / 2, y, len / 2);
        divide(x, y + len / 2, len / 2);
        divide(x + len / 2, y + len / 2, len / 2);

        return;
      }
    }
  }
  if (paper[y][x] == 0)
    white++;
  else
    blue++;
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> paper[i][j];
    }
  }

  divide(0, 0, N);

  cout << white << '\n';
  cout << blue << '\n';
}