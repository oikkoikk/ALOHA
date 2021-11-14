#include <iostream>

#define max(a, b) a > b ? a : b
using namespace std;

int N;
int ans[2];
int chess[11][11];
int l[19]; // 우하향 대각선(10X10일 때 최대 19칸)
/* 4 5 6 7 8
   3 4 5 6 7
   2 3 4 5 6
   1 2 3 4 5 
   0 1 2 3 4 */
int r[19]; // 우상향 대각선(10X10일 때 최대 20칸)
/* 0 1 2 3 4
   1 2 3 4 5
   2 3 4 5 6
   3 4 5 6 7
   4 5 6 7 8 */

// 놓을 수 있는 비숍의 최대개수를 구하는 함수
// 흑/백, 두 가지 경우로 나누어 계산

void Backtracking(int row, int col, int count, int color)
{
    //흑 백 번갈아 나오는 것을 고려
    if (col >= N)
    {
        row++;
        if (col % 2 == 0)
            col = 1;
        else
            col = 0;
    }
    //끝까지 가면 값 저장
    if (row >= N)
    {
        ans[color] = max(ans[color], count);
        return;
    }
    //체스판에 놓을 수 있는지, 대각선 방향에 비숍이 없는지 체크
    if (chess[row][col] && !l[col - row + N - 1] && !r[row + col])
    {
        l[col - row + N - 1] = r[row + col] = 1;
        Backtracking(row, col + 2, count + 1, color);
        l[col - row + N - 1] = r[row + col] = 0;
    }
    //놓을 수 없으면 다음으로 이동
    Backtracking(row, col + 2, count, color);
}

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> chess[i][j];
        }
    }

    Backtracking(0, 0, 0, 0); //흑
    Backtracking(0, 1, 0, 1); //백

    cout << ans[0] + ans[1];

    return 0;
}
