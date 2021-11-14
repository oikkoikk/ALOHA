//하노이 탑 이동 순서 문제!
//분할 정복 & 재귀호출 대표 예제
#include <iostream>
#include <cmath>

using namespace std;

int N, cnt, times;

void Hanoi(int N, int from, int by, int to)
{
    if (N == 1)
    {
        //기저조건 -> 1개 남았으면, 그냥 이동!
        cout << from << ' ' << to << '\n';
    }
    else
    //아래의 해결방식을 분할 정복으로 반복
    {
        //N-1개를 A에서 B로 이동
        Hanoi(N - 1, from, to, by);
        //A에 남아있는 가장 큰 원반을 C로 이동
        cout << from << ' ' << to << '\n';
        //N-1개를 B에서 C로 이동
        Hanoi(N - 1, by, from, to);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cnt = pow(2,N) -1; //총 이동 횟수는 2^N-1이다!

    cout << cnt << '\n';
    Hanoi(N, 1, 2, 3);

    return 0;
}