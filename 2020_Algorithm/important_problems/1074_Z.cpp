#include <iostream>
#include <cmath>

using namespace std;

int N, R, C, len, flag;
long long cnt = -1;

void Divide(int nowLen, int x, int y) //Divide & Conquer!
{
    if (nowLen / 2 > 1)
    {
        nowLen /= 2;
        Divide(nowLen, x, y); //Z자 순서로 재귀호출 되도록!
        Divide(nowLen, x + nowLen, y);
        Divide(nowLen, x, y + nowLen);
        Divide(nowLen, x + nowLen, y + nowLen);
    }
    else
    {

        //기저 조건!
        if (flag)
            return;

        else if (flag == 0)
        {
            //해당 좌표가 포함된 2*2블럭이 아니라면, 4만큼 카운트하고 패스!
            if (!((x <= C && C <= x + 1) && (y <= R && R <= y + 1)))
            {
                cnt += 4;
                return;
            }
            else
            {
                if (x == C)
                {
                    if (y == R)
                        cnt += 1;
                    else
                        cnt += 3;
                }
                else
                {
                    if (y == R)
                        cnt += 2;
                    else
                        cnt += 4;
                }
                //이미 찾았는데, 뒤에 남은 횟수를 더하지 않도록 flag 표시!
                flag = 1;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R >> C;
    len = pow(2, N); //정사각형 변의 길이를 저장

    Divide(len, 0, 0);

    if (cnt == -1) //cnt가 초기 상태 그대로일 경우 처리!
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << cnt;
    }

    return 0;
}