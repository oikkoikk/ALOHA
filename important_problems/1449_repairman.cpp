#include <iostream>
#include <algorithm>

using namespace std;

int N, L, cnt;
int loca[1000];

int main()
{
  cin >> N >> L;

  for (int i = 0; i < N; i++)
  {
    cin >> loca[i];
  }
  sort(loca, loca + N);

  int start = loca[0];
  cnt++;

  for (int i = 1; i < N; i++)
  {
    if (loca[i] - start > (L - 1))
    {
      cnt++;
      start = loca[i];
    }
  }
  cout << cnt;
}