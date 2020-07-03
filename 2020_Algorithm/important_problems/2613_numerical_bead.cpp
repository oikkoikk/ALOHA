#include <iostream>
#include <vector>

using namespace std;

long long N, M;
long long lower = 999;
long long answer[301];
long long ansSize = 1;
vector<long long> Arr;

bool Grouping(long long val) // 각 그룹의 원소의 합이 mid를 넘지 않도록
{
    long long groupNow = 1;
    long long sum = 0;

    for (long long i = 0; i < N; i++)
    {
        if (Arr[i] > val)
        {
            return false;
        }
        sum += Arr[i];
        if (sum > val) //주어진 mid를 넘으면
        {
            groupNow += 1; //그룹 하나 더 만든다!
            sum = Arr[i];
        }
    }
    if (groupNow <= M)
    {
        return true;
    }
    else
        return false;
}
void ParametricSearch(long long start, long long end)
{
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        if (Grouping(mid))
        {
            end = mid - 1; //최대한 작은 값으로 설정하기 위해
            if (lower > mid)
            {
                lower = mid; //최대한 작은 값으로 설정하기 위해 22
            }
        }
        else
        {
            start = mid + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (long long i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        Arr.push_back(num);
    }
    ParametricSearch(1, N * 100);

    cout << lower << '\n';
    // 그룹의 원소 개수 출력
    int num = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += Arr[i];
        num++;
        if (sum > lower) //최댓값에 맞춰서!
        {
            sum = Arr[i];
            answer[ansSize] = num - 1; //이전 개수는 answer 벡터에 저장 (ansSize는 1부터 시작)
            ansSize++;
            num = 1;
        }
    }
    answer[ansSize] = num;
    //마지막 조건 확인 (무작정 최댓값에 맞춰서 그룹을 자르면 반례가 발생함)
    int difference = (M - ansSize); //정해진 그룹 개수와, 최댓값으로 구분한 그룹 개수의 오차를 확인
    for (int i = 1; i <= ansSize; i++)
    {
        if (answer[i] == 1)
            cout << answer[i] << ' ';
        else
        {
            while (answer[i] >= 2 && difference >= 1) //그룹 개수 맞춰주기 위해 분할!
            {
                cout << "1 ";
                answer[i]--;
                difference--;
            }
            cout << answer[i] << ' ';
        }
    }
}
/*
반례 예시
<input>

9 6
1 1 1 1 1 1 1 1 1

<output>

2
2 2 2 1 1 1
*/