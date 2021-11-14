#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1'000'001;
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
        //DP에 들어있는게 없거나, 가장 큰 값이 들어온 경우(고민할 것 없이 맨 뒤에 넣는다!)
        else
        {
            int index = (lower_bound(DP.begin(), DP.end(), arr[i]) - DP.begin());
             //arr[i]보다 크거나 같은 최소의 index를 찾는다.(lower_bound) (iterator 형식이므로, int에 맞추려면 DP.begin()으로 빼줘야 한다!)
            DP[index] = arr[i];
        }
        //DP의 요소가 실제 LIS의 요소는 아니지만, 길이는 동일하다!
    } //O(NlogN)
    cout << DP.size();
}