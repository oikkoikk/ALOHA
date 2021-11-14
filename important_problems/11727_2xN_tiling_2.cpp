// 2xN 타일링 2
//DP & Memoization
#include <cstdio>
#include <cstring>

int memo[1001];

int solve(int n)
{
    if (n <= 1) //n=1 이면 2x1밖에 없다!
        return 1;
    int &ret = memo[n];
    if (ret != -1)
    {
        return ret;
    }
    ret = solve(n - 1) % 10007 + (2 * solve(n - 2)) % 10007; //n-2에서 2가지의 방법이 존재! (= or ㅁ)
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(memo, -1, sizeof(memo)); //초기화
    printf("%d", solve(n) % 10007);
}