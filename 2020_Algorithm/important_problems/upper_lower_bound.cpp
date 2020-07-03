#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, aim;
int mid;
vector<int> arr;
int UpperBound(int start, int end) //인자는 인덱스 기준!
{
    while(start < end)
    {
        mid = (start + end) / 2;
        if (arr[mid] >= aim)
        {
            end = mid;
        }
        else if (arr[mid] < aim)
        {
            start = mid +1;
        }
    }
    return start + 1; //반환은 인덱스가 아니라 순서 기준!
}
int LowerBound(int start, int end) //인자는 인덱스 기준!
{
    while(start < end)
    {
        mid = (start + end) / 2;
        if (arr[mid] > aim)
        {
            end = mid-1;
        }
        else if (arr[mid] <= aim)
        {
            start = mid;
        }
    }
    return start +1; //반환은 인덱스가 아니라 순서 기준!
}
int main()
{
    cin >> N >> aim;

    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    cout << "upperbound order(1~) : " << UpperBound(0, N-1) << endl;
    cout << "lowerbound order(1~) : " << LowerBound(0, N-1);
}