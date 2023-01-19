#include <iostream>

using namespace std;

int board[9][9];
int N, king_x, king_y, stone_x, stone_y;

bool is_ok(int move_x, int move_y, string sub)
{
  if (sub == "king")
  {
    if (!(1 <= king_x + move_x && king_x + move_x <= 8 && 1 <= king_y + move_y && king_y + move_y <= 8))
    {
      return false;
    }
    return true;
  }
  else
  { //돌이 움직일 수 있는지 확인
    if (!(1 <= stone_x + move_x && stone_x + move_x <= 8 && 1 <= stone_y + move_y && stone_y + move_y <= 8))
    {
      return false;
    }
    return true;
  }
}

void move(string command)
{
  int move_x, move_y;

  if (command == "R")
  {
    move_x = 1;
    move_y = 0;
  }
  else if (command == "L")
  {
    move_x = -1;
    move_y = 0;
  }
  else if (command == "B")
  {
    move_x = 0;
    move_y = 1;
  }
  else if (command == "T")
  {
    move_x = 0;
    move_y = -1;
  }
  else if (command == "RT")
  {
    move_x = 1;
    move_y = -1;
  }
  else if (command == "LT")
  {
    move_x = -1;
    move_y = -1;
  }
  else if (command == "RB")
  {
    move_x = 1;
    move_y = 1;
  }
  else if (command == "LB")
  {
    move_x = -1;
    move_y = 1;
  }

  if (is_ok(move_x, move_y, "king"))
  {
    king_x += move_x;
    king_y += move_y;
    if (king_x == stone_x && king_y == stone_y)
    //왕을 움직였는데, 돌이랑 겹친다면 돌도 움직여 줘야 함
    {
      if (is_ok(move_x, move_y, "stone"))
      {
        stone_x += move_x;
        stone_y += move_y;
      }
      else //만약 돌이 움직일 수 없는 상황이라면, 롤백
      {
        king_x -= move_x;
        king_y -= move_y;
      }
    }
  }
}

int main()
{
  string temp;

  cin >> temp;
  king_x = temp[0] - 'A' + 1;
  king_y = 8 - (temp[1] - '0') + 1;
  cin >> temp;
  stone_x = temp[0] - 'A' + 1;
  stone_y = 8 - (temp[1] - '0') + 1;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    string temp;

    cin >> temp;

    move(temp);
  }

  cout << (char)('A' + king_x - 1) << 9 - king_y << endl;
  cout << (char)('A' + stone_x - 1) << 9 - stone_y << endl;
}