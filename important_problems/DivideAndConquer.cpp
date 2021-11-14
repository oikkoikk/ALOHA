//합병정렬(분할정복 이용)
//단계를 나눌 수록 문제의 양은 2배로 늘어난다!
//각 단계에서의 총 연산량은 약 O(N)
//ex) 1단계: 1*O(N) 2단계: 2*O(N/2) ...
//따라서 총 시간복잡도는 약 O(NlogN)!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, number, sorted[500013];
vector<int> vec;

void merge(int start, int mid, int end)
{
    int i = start;   //전반부 배열 시작 idx
    int j = mid + 1; //후반부 배열 시작 idx
    int k = start;   //sorted에 저장할 때 쓰는 idx

    while (i <= mid && j <= end)
    {
        if (vec[i] <= vec[j])
        {
            sorted[k] = vec[i];
            //저장하면, 다음 수로 넘어간다!
            i++;
        }
        else
        {
            sorted[k] = vec[j];
            //마찬가지로, 저장하면 다음 수로 넘어간다!
            j++;
        }
        //다음 인덱스로 넘어간다!
        k++;
    }
    if (i > mid) //전반부 배열이 먼저 끝나버렸다면,
    {
        for (int t = j; t <= end; t++)
        {
            sorted[k] = vec[t]; //후반부 배열 나머지 전부 순서대로 넣어버리기!
            k++;
        }
    }
    else //반대로, 후반부 배열이 먼저 끝나버렸다면,
    {
        for (int t = i; t <= mid; t++)
        {
            sorted[k] = vec[t]; //전반부 배열 나머지 전부 순서대로 넣어버리기!
            k++;
        }
    }
    for (int t = start; t <= end; t++)
    {
        vec[t] = sorted[t]; //다음 conquer를 위해 sorted의 값 vec에 저장!
    }
}
void merge_sort(int start, int end)
{
    //크기가 1이 될 때까지 분할!
    if (start < end)
    {
        int mid = (start + end) / 2;
        //재귀호출로 분할!
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        //다시 정복!
        merge(start, mid, end);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        vec.push_back(number);
    }
    merge_sort(0, N - 1);
    for (int i = 0; i < N; i++)
    {
        cout << sorted[i];
    }
}