#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int map[101][101]; // map기능 + 뱀의 몸통을 dir 인덱스(1~4)로 표시
bool apple[101][101];
int time;
pair<int, int> dir[5] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//                                왼       오       아래      위
pair<int, int> snake_head = {1, 1};
pair<int, int> snake_tail = {1, 1};
int snake_dir = 2;

queue<pair<int, char>> command;
bool is_game_over()
{
  //맵 밖으로 벗어난 경우
  if (1 > snake_head.first || snake_head.first > N || 1 > snake_head.second || snake_head.second > N)
    return true;
  //몸통에 부딪힌 경우
  if (map[snake_head.second][snake_head.first] != 0)
    return true;

  return false;
}
void move()
{
  time++;

  //머리부터 이동!
  snake_head.first += dir[snake_dir].first;
  snake_head.second += dir[snake_dir].second;
  if (is_game_over())
  {
    cout << time << endl;

    exit(0);
  }
  map[snake_head.second][snake_head.first] = snake_dir;

  if (!apple[snake_head.second][snake_head.first])
  {
    //사과가 없으면
    int tail_dir = map[snake_tail.second][snake_tail.first];
    map[snake_tail.second][snake_tail.first] = 0;

    snake_tail.first += dir[tail_dir].first;
    snake_tail.second += dir[tail_dir].second;
  }
  else
    apple[snake_head.second][snake_head.first] = false;
}

void dir_transition(char trans_dir)
{
  // 1:왼 2:오 3:아래 4:위
  if (snake_dir == 1)
  {
    if (trans_dir == 'L')
      snake_dir = 3;
    else
      snake_dir = 4;
  }
  else if (snake_dir == 2)
  {
    if (trans_dir == 'L')
      snake_dir = 4;
    else
      snake_dir = 3;
  }
  else if (snake_dir == 3)
  {
    if (trans_dir == 'L')
      snake_dir = 2;
    else
      snake_dir = 1;
  }
  else if (snake_dir == 4)
  {
    if (trans_dir == 'L')
      snake_dir = 1;
    else
      snake_dir = 2;
  }

  map[snake_head.second][snake_head.first] = snake_dir;
}

int main()
{
  cin >> N >> K;

  map[1][1] = 2;

  for (int i = 0; i < K; i++)
  {
    int y, x;
    cin >> y >> x;

    apple[y][x] = true;
  }

  cin >> L;

  for (int i = 0; i < L; i++)
  {
    char C;
    int X;

    cin >> X >> C;
    command.push({X, C});
  }

  while (!command.empty())
  {
    pair<int, char> comm = command.front();
    command.pop();

    int trans_time = comm.first;
    char trans_dir = comm.second;

    while (time < trans_time)
    {
      move();
    }
    //시간이 되면 방향전환
    dir_transition(trans_dir);
  }

  //방향전환 후에도 게임이 끝날 때까지 진행(직진)
  while (true)
  {
    move();
  }
}