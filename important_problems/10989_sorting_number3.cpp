//배열 표시로 정렬!
#include <iostream>

using namespace std;

int num[10001];
int N, temp, maxnum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        num[temp]++;
        if (maxnum < temp)
        {
            maxnum = temp; //최댓값 저장
        }
    }
    for (int i = 1; i <= maxnum; i++) //1부터 최댓값까지
    {
        if (num[i] > 0)
        {
            while (num[i] > 0) //중복된 값 고려!
            {
                cout << i << '\n';
                num[i]--;
            }
        }
    }

    return 0;
}