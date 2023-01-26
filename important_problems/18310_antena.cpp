#include <iostream>
#include <algorithm>

using namespace std;

int N;
int houses[200'000];

int main()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> houses[i];
  }

  sort(houses, houses + N);

  int min_1 = N > 1 ? (int)(N / 2) - 1 : 0;
  int min_2 = (int)(N / 2);

  cout << ((N % 2 == 0) ? houses[min_1] : houses[min_2]);
}