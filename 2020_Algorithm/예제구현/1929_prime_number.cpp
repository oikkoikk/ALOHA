//소수를 빠르게 구할 수 있는 에라토스테네스의 체!
//주어진 수의 '제곱근'까지만 체크해봐도 괜찮다!

/*
(만일 어떤 자연수 x에 sqrt(x)보다 큰 소인수가 존재한다면, 
x를 그 소인수로 나눈 값은 sqrt(x)보다 작아야 하기 때문에,
2부터 순차적으로 i를 증가시키는 동안 이미 그 수로 나누어보았을 것이기 때문
*/
#include <iostream>
#include <cmath>

using namespace std;

int M, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    int prime[N + 1];

    for (int i = 2; i <= N; i++)
    {
        prime[i] = i;
    }

    for (int i = 2; i <= sqrt(N); i++) //주어진 수의 '제곱근'까지만 체크해도 된다!
    {
        if (prime[i] == 0)
            continue;
        for (int j = i + i; j <= N; j += i) //2의 배수부터 지워나간다!
        {
            prime[j] = 0;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (prime[i] != 0)
        {
            cout << i << '\n';
        }
    }
}