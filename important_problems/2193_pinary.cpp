#include <iostream>

using namespace std;

int N;
long long PN[91][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    PN[1][0] = 0;
    PN[1][1] = 1;
    PN[2][0] = 1;
    PN[2][1] = 0;

    cin >> N;

    for (int i = 3; i <= N; i++)
    {
        PN[i][0] = PN[i - 1][1] + PN[i - 1][0];
        PN[i][1] = PN[i - 1][0];
    }

    cout << PN[N][0] + PN[N][1];
}