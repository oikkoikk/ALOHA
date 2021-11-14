//다이나믹 프로그래밍(BOTTOM-UP)
//초기 설정만 잘 해주면, 쉽게 구할 수 있다!
#include <iostream>
#include <vector>

using namespace std;

int N, M, S, E;
vector<int> palindrome;
int DP[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;

        palindrome.push_back(num);
        DP[i][i] = 1;
    }
    int end;

    for (int nowLen = 1; nowLen < N; nowLen++) //체크할 수열?의 길이 (2부터 쭉 ㄱㄱ)
    {
        for (int start = 0; start + nowLen < N; start++) //시작할 수열 인덱스
        {
            end = start + nowLen;

            if (nowLen == 1) //2자리 체크할 때만 따로 초기설정!
            {
                if (palindrome[start] == palindrome[end])
                {
                    DP[start][end] = 1;
                }
            }

            else if (DP[start + 1][end - 1] == 1) //가운데 있는게 펠린드롬이고, 양 끝이 같으면, 펠린드롬!
            {
                if (palindrome[start] == palindrome[end])
                {
                    DP[start][end] = 1;
                }
            }
        }
    }
    cin >> M;
    while (M--)
    {
        cin >> S >> E;

        cout << DP[S - 1][E - 1] << '\n';
    }
}