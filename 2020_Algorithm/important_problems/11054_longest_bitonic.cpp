// DP로 최장증가, 최장감소 구하기
#include <iostream>

using namespace std;

const int MAX = 1000 + 1;

int N;
int sequence[MAX];
int increasing[MAX]; //increasing[idx] : idx까지의 최장증가수열의 길이
int decreasing[MAX]; //decreasing[idx] : idx부터의 최장감소수열의 길이

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> sequence[i];
    }

    for (int i = 1; i <= N; i++)
    {
        increasing[i] = 1; //초기 설정

        for (int j = 1; j <= i; j++) //이전 상황 체크
        {
            //'최장'증가수열이 될 수 있도록 조건 체크
            if (sequence[j] < sequence[i] && increasing[i] < increasing[j] + 1)
            {
                increasing[i] = increasing[j] + 1;
            }
        }
    }

    for (int i = N; i >= 1; i--)
    {
        decreasing[i] = 1; //초기 설정 22

        for (int j = N; j >= i; j--) //이전 상황 체크
        {
            //'최장'감소수열이 될 수 있도록 조건 체크
            if (sequence[i] > sequence[j] && decreasing[j] + 1 > decreasing[i])
            {
                decreasing[i] = decreasing[j] + 1;
            }
        }
    }

    int result = 0;

    for (int i = 0; i <= N; i++)
    { //i 자기자신이 중복되므로 -1!
        result = (result < increasing[i] + decreasing[i] - 1) ? increasing[i] + decreasing[i] - 1 : result;
    }
    cout << result;

    return 0;
}