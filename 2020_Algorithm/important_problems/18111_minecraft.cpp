#include <iostream>
using namespace std;

int main()
{
  int land[500][500];
  int targetFloor = -1;
  int targetTime = 987654321;
  int N,M,B;

  cin >> N >> M >> B;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      cin >> land[i][j];
    }
  }
  for(int floor = 0; floor <257; floor++)
  {
    int inventory = B;
    int time = 0;

    for(int i=0; i<N; i++)
    {
      for (int j=0; j<M; j++)
      {
        if(floor > land[i][j])
        {
          inventory-=(floor - land[i][j]);
          time +=(floor - land[i][j]);
        }
        else if(floor < land[i][j])
        {
          inventory +=(land[i][j] - floor);
          time += 2*(land[i][j] - floor);
        }
      }
    }
    if(inventory < 0)
    {
      continue;
    }
    else if(time <= targetTime)
    {
      targetTime = time;
      targetFloor = floor;
    }
  }
  cout << targetTime << ' ' << targetFloor;
}