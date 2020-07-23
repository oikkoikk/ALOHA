//브루트 포스
//재귀호출

#include <iostream>
#include <string>

using namespace std;
int N, K, numInt;
int cnt = 987654321;
int button[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void find(string num)
{
    for (int i = 0; i < 10; i++)
    {
        if (button[i])
        {
            string temp = num + to_string(i); //하나하나씩 붙여가며 검사!
            cnt = min(cnt, abs(numInt - stoi(temp)) + (int)temp.size());

            if (temp.size() < 6) //최대가 500'000번까지이기 때문
            {
                find(temp); //가능한 모든 수를 찾아서 cnt와 비교!
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numInt >> N;

    cnt = min(cnt, abs(100 - numInt)); //수빈이가 현재 100번 채널에 있으므로

    for (int i = 0; i < N; i++)
    {
        cin >> K;
        button[K] = 0;
    }

    if (N < 10)
    {
        find("");
    }

    cout << cnt;
}