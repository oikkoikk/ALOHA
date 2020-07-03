#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000005;
int arr[MAX];
vector <int> DP;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    char ar[10];
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> arr[i];
    }
    for(int i =1; i<=N; i++)
    {
        if(DP.size() == 0 || arr[i] > DP.back()) 
            DP.push_back(arr[i]);
        //DP의 마지막 값보다 큰 것이 있으면(연속해서 증가하도록) push
        else
        {
            int index = (lower_bound(DP.begin(), DP.end(), arr[i]) - DP.begin());
             //arr[i] 이상(lower_bound)의 값이 처음 나타나는 위치에 arr[i] 넣는다(iterator 반환이므로 begin을 빼서 index로!)
            DP[index] = arr[i];
        }
        //결과적으로 DP 배열의 길이 = LIS의 길이(원소가 같지는 않음 그저 길이!)
    } //O(NlogN)
    cout << DP.size();
}