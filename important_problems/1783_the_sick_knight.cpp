#include <iostream>

using namespace std;

int N, M, cnt;

int main()
{
  cin >> N >> M;
  if (N == 1) // 세로가 1이면 이동 불가
    cout << 1;

  else if (N == 2) // 세로가 2까지는 최대 4번(오른쪽으로는 2*x로만 가능)
    cout << min(4, (M + 1) / 2);

  else
  {
    // 가로가 6까지는 최대 4칸 가능
    if (M <= 6)
      cout << min(4, M);
    else // 2번 3번 한번씩 나머지는 1번, 4번(그리디)
      cout << M - 2;
  }
}