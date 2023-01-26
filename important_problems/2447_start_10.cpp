#include <iostream>

using namespace std;

int N;
int canvas[6561][6561];

void drawing(int start_x, int start_y, int len)
{
  if (len == 1)
  {
    canvas[start_y][start_x] = 1;
    return;
  }

  int next_len = len / 3;

  drawing(start_x, start_y, next_len);
  drawing(start_x + next_len, start_y, next_len);
  drawing(start_x + 2 * next_len, start_y, next_len);
  drawing(start_x, start_y + next_len, next_len);
  drawing(start_x + 2 * next_len, start_y + next_len, next_len);
  drawing(start_x, start_y + 2 * next_len, next_len);
  drawing(start_x + next_len, start_y + 2 * next_len, next_len);
  drawing(start_x + 2 * next_len, start_y + 2 * next_len, next_len);
}

int main()
{
  cin >> N;

  drawing(0, 0, N);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << (canvas[i][j] ? '*' : ' ');
    }
    cout << '\n';
  }
}