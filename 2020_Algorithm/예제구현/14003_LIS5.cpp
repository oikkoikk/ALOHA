//LIS(NlogN 방식)문제!
//NlogN방식으로는 LIS 길이만 알 수 있지만,
//인덱스를 따로 저장하여 역추적해가며 요소를 알아낼 수 있다!
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, temp;
int pos = -1;                   //history에 인덱스 넣기 위한 pos!
vector<int> sequence;           //입력받은 수열 저장
vector<int> LIS;                //LIS의 '길이'만 얻을 수 있음
vector<pair<int, int>> history; //LIS 요소를 얻기위한 vector
stack<int> result;              //LIS 요소를 저장하는 stack

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        sequence.push_back(temp);
    }

    for (int i = 0; i < N; i++)
    {
        if (LIS.size() == 0 || sequence[i] > LIS.back())
        {
            LIS.push_back(sequence[i]);
            pos++; //history에 인덱스 저장하기 위해
            history.push_back({pos, LIS.back()});
        }
        else
        {
            //(lower_bound() - LIS.begin()) 으로 index 찾기
            int index = (lower_bound(LIS.begin(), LIS.end(), sequence[i]) - LIS.begin());
            LIS[index] = sequence[i];
            history.push_back({index, LIS.back()});
        }
    }
    temp = LIS.size() - 1;

    for (int i = N - 1; i >= 0; i--)
    {
        if (temp == history[i].first) //역추적하면서 LIS 요소 stack에 저장
        {
            result.push(sequence[i]);
            temp--;
        }
    }

    cout << LIS.size() << '\n';
    for (int i = 0; i < LIS.size(); i++)
    {
        cout << result.top() << ' ';
        result.pop();
    }

    return 0;
}