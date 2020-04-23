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
        //DP�� ������ ������ ū ���� ������(�����ؼ� �����ϵ���) push
        else
        {
            int index = (lower_bound(DP.begin(), DP.end(), arr[i]) - DP.begin());
             //arr[i] �̻�(lower_bound)�� ���� ó�� ��Ÿ���� ��ġ�� arr[i] �ִ´�(iterator ��ȯ�̹Ƿ� begin�� ���� index��!)
            DP[index] = arr[i];
        }
        //��������� DP �迭�� ���� = LIS�� ����(���Ұ� ������ ���� ���� ����!)
    } //O(NlogN)
    cout << DP.size();
}