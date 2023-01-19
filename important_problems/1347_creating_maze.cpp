#include <iostream>

using namespace std;

int maze[101][101];
int N;
string command;
int now_dir;
int now_x = 50;
int now_y = 50;
pair<int, int> start, last;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
//                  ↓       ←         ↑       →

void move(char comm)
{
  if (comm == 'R')
  {
    now_dir = (now_dir + 1) % 4;
  }
  else if (comm == 'L')
  {
    if (now_dir == 0)
      now_dir = 3;
    else
      now_dir -= 1;
  }
  else if(comm == 'F')
  {
    now_x += dir[now_dir][1];
    now_y += dir[now_dir][0];
    maze[now_y][now_x] = 1;
  }
}

int main()
{
  cin >> N;

  cin >> command;

  maze[now_y][now_x] = 1;
  start = {987654321, 987654321};
  last = {-1, -1};

  for (int i = 0; i < command.size(); i++)
  {
    move(command[i]);
  }
  for (int i = 0; i < 101; i++)
  {
    for (int j = 0; j < 101; j++)
    {
      if (maze[i][j] == 1)
      {
        if (i < start.second)
          start.second = i;
        if (j < start.first)
          start.first = j;
        if (i > last.second)
          last.second = i;
        if (j > last.first)
          last.first = j;
      }
    }
  }

  for (int i = start.second; i <= last.second; i++)
  {
    for (int j = start.first; j <= last.first; j++)
    {
      if (maze[i][j])
        cout << '.';
      else
        cout << '#';
    }
    cout << endl;
  }
}