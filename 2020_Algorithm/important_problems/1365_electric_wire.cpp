//LIS 문제
//길이만 알 수 있다! (부분수열 자체를 알아내려면, 길이 가지고 역추적!)
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> DP;
    int arr[MAX] = {
        0,
    };

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++)
    {
        if (DP.size() == 0 || arr[i] > DP.back())
            DP.push_back(arr[i]);
        else
        {
            int index = (lower_bound(DP.begin(), DP.end(), arr[i]) - DP.begin());
            DP[index] = arr[i];
        }
    }
    cout << N - DP.size();
}