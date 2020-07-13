/*
3-> 1     (1개)
2-> 1 3   (2개)
1-> 1 2 3 (3개)
*/
#include <iostream>

using namespace std;

long long result;
int N, group;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    N--; //1부터 시작하므로 N을 1만큼 줄여서 편리하게 구현!

    for (int i = N + 1, times = N / i + 1; i > 0; i = N / times) //횟수가 변화하는 시점으로 바로 점프!
    {
        times = N / i + 1;
        group = i - (N / times);
        result += (times) * (group); //횟수가 동일하게 나타나는 구간은 한꺼번에 계산!
    }

    cout << result;
}