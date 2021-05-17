#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num, sum;
vector<int> weight;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        weight.push_back(num);
    }
    //오름차순 정렬!
    sort(weight.begin(), weight.end());

    for (int i = 0; i < N; i++)
    {
        //누적합+1보다 이번 추의 무게가 더 무거우면,
        //중간에 구할 수 없는 빈 영역이 생긴다..!
        if (sum + 1 < weight[i])
            break;
        sum += weight[i];
    }

    cout << sum + 1 << '\n';

    return 0;
}