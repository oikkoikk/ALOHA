//전대프연 UCPC 2019 예선 문제
//DP로 모든 경우의 수를 구해서 다 더한다음, 전체 경우의 수로 나눈다.
#include <iostream>
#include <cstring>

using namespace std;

int N;
double sum, result;
// DP[a,b,c,left] = 최근 던진눈 3개가 (a,b,c)이고 앞으로 던질 수 있는 횟수가 left일때
// 받을 수 있는 상금의 기댓값
// 모든 DP case에 대해 DP를 구하고 그걸 다 더한다음 6*6*6으로 나누면됨
double DP[7][7][7][1001];

// 상금 계산
int cal(int a, int b, int c)
{
    if (a == b && b == c) //1번 케이스
        return 10000 + a * 1000;

    else if (a == b || b == c || c == a) //2번 케이스
        return 1000 + (a == b ? a : c) * 100;

    else
    {
        int maxd = a;
        maxd = max(maxd, b);
        maxd = max(maxd, c);

        return maxd * 100; //3번 케이스
    }
}
//재귀로 DP
double solve(int a, int b, int c, int left)
{
    double curMoney = cal(a, b, c); //상금 계산

    if (left == 0) //더 이상 기회가 없으면, 그대로 상금 return (재귀 stop)
        return curMoney;

    if (DP[a][b][c][left] > 0) //이미 계산된 값이라면, 패스
        return DP[a][b][c][left];
    // 현재 기댓값 vs 더 굴리는 기댓값 비교
    else
    {
        double more = 0;
        for (int i = 1; i <= 6; i++)
        {
            more += solve(b, c, i, left - 1);
        }
        return DP[a][b][c][left] = max(curMoney, (more / 6)); //1번 더 굴렸으니 (more/6)
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    memset(DP, -1, sizeof(DP));

    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
            {
                sum += solve(i, j, k, N - 3);
            }
    cout.precision(16);
    cout << (sum / (6 * 6 * 6));

    return 0;
}