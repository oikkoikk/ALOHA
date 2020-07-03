#include <iostream>
using namespace std;

const int MAX = 50;

int M, N;
char Chess[MAX][MAX];

int whiteFirst(int x, int y)
{

    int count = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (Chess[i][j] != 'W')
                        count++;
                }
                else
                {
                    if (Chess[i][j] != 'B')
                        count++;
                }
            }
            else
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (Chess[i][j] != 'B')
                        count++;
                }
                else
                {
                    if (Chess[i][j] != 'W')
                        count++;
                }
            }
        }
    }
    return count;
}

int blackFirst(int x, int y)
{
    int count = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (Chess[i][j] != 'B')
                        count++;
                }
                else
                {
                    if (Chess[i][j] != 'W')
                        count++;
                }
            }
            else
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (Chess[i][j] != 'W')
                        count++;
                }
                else
                {
                    if (Chess[i][j] != 'B')
                        count++;
                }
            }
        }
    }
    return count;
}

void makeChess()
{
    int whiteMin;
    int blackMin;
    int result = 9999;

    for (int i = 0; i < N; i++)
    {
        if (i + 8 > N)
            break; //체스판 만들 수 없으면 패스!

        for (int j = 0; j < M; j++)
        {
            if (j + 8 > M)
                break; //체스판 만들 수 없으면 패스!

            whiteMin = whiteFirst(i, j); //W으로 시작하게끔 할 때의 최솟값 구하기
            blackMin = blackFirst(i, j); //B으로 시작하게끔 할 때의 최솟값 구하기
            result = min(result, min(whiteMin, blackMin));
        }
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Chess[i][j];
        }
    }

    makeChess();

    return 0;
}