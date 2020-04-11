// 분할정복 만들어보기 ^_________^
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, number, sorted[500013];
vector<int> vec;

void merge(int start, int mid, int end)
{
    int i = start;   //첫 번째 배열 시작 idx
    int j = mid + 1; //두 번째 배열 시작 idx
    int k = start;   //sorted에 저장할 때 쓰는 idx

    while (i <= mid && j <= end)
    {
        if (vec[i] <= vec[j])
        {
            sorted[k] = vec[i];
            i++;
        }
        else
        {
            sorted[k] = vec[j];
            j++;
        }
        k++;
    }
    if (i > mid) //첫 번째 배열이 끝나버렸을 때
    {
        for (int t = j; t <= end; t++)
        {
            sorted[k] = vec[t]; //두 번째 배열 남은 요소 그대로 넣기
            k++;
        }
    }
    else //두 번째 배열이 끝나버렸을 때
    {
        for (int t = i; t <= mid; t++)
        {
            sorted[k] = vec[t]; //첫 번째 배열 남은 요소 그대로 넣기
            k++;
        }
    }
    for (int t = start; t <= end; t++)
    {
        vec[t] = sorted[t]; //다음 conquer를 위해 sorted의 값 vec에 저장
    }
}
void merge_sort(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        vec.push_back(number);
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << sorted[i];
    }
}