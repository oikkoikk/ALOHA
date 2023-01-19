#include <iostream>
#include <algorithm>

using namespace std;

// 가장 긴 변의 길이 < 다른 두 변의 길이의 합
int N;
int straw[1'000'001];
bool comp(int a, int b)
{
  return a > b;
}
int main()
{
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> straw[i];
  }

  sort(straw + 1, straw + N + 1, comp); // 내림차순

  for (int i = 1; i <= N - 2; i++)
  {
    if (straw[i] < straw[i + 1] + straw[i + 2])
    {
      cout << straw[i] + straw[i + 1] + straw[i + 2];
      // 연속된 3개만 보면된다! -> 연속된 3개로 못만들면, 그 보다 작은 빨대로는 당연히 못 만들테니까..!
      break;
    }
    if (i == N - 2)
      cout << -1;
  }
}