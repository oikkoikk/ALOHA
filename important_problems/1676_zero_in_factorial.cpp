/*
ex) 20! = 2432902008176640000
    따라서 답은 4

        500!을 구할 수는 없다!!
        2*5 -> 0이 1개 붙음
        (2*5)*(2*5) -> 0이 2개 붙음
        ...
    1~N(최대 500)까지의 수에서 2와 5가 몇 개 들어가는지 체크!!
    2의 개수가 5의 개수보다는 무조건 크거나 같을 수밖에 없으므로, 5의 개수만 체크해도 무방!
*/
#include <iostream>

using namespace std;

int N, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        if (i % 5 == 0)
        {
            cnt++;
        }
        if (i % 25 == 0)
        {
            cnt++;
        }
        if (i % 125 == 0)
        {
            cnt++;
        }
    }
    cout << cnt;
}