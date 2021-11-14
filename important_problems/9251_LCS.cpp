//LCS (최장 공통 부분 수열)
//DP 배열을 통해 아래와 같은 규칙 적용!
#include <iostream>
#include <algorithm>

using namespace std;

char str1[1002], str2[1002];
int DP[1001][1001], i, j;
/*
만약, 비교하는 위치의 문자가 서로 같으면 
    현재 위치의 값 = 왼쪽 대각선 값 + 1 (배열 범위를 벗어났으면 0이라고 가정 )
다르다면,  
    현재 위치의 값 = MAX{왼쪽 값, 위쪽 값}

DP[i][j] : i까지의 문자열과 j까지의 문자열 사이의 LCS 길이

ex)
0	A	C	A	Y	K	P
0	0	0	0	0	0	0
C	0	1 	1	1	1	1
A	1	1	2	2	2	2
P	1	1	2	2	2	3
C	1	2	2	2	2	3
A	1	2	3	3	3	3
K	1	2	3	3	4	4

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str1 + 1 >> str2 + 1;

    for (i = 1; str1[i]; i++)
    {
        for (j = 1; str2[j]; j++)
        {
            DP[i][j] = max({DP[i][j - 1], DP[i - 1][j], DP[i - 1][j - 1] + (str1[i] == str2[j])});
        }
    }
    cout << DP[i - 1][j - 1];

    return 0;
}