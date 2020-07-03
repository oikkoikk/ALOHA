#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> number;
vector<char> result;
int seq[100'001];
int N, pos = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }

    for (int i = 1; i <= N; i++)
    {
        number.push(i);
        result.push_back('+'); //1부터 오름차순으로 채워나가다가

        while ((!number.empty()) && (number.top() == seq[pos])) //같은게 있으면 pop!
        {
            number.pop();
            result.push_back('-');
            pos++; //index 기억
        }
    }

    if (!number.empty()) //1부터 N까지 다 돌았는데도 남아있으면, 불가능!
    {
        cout << "NO" << '\n';
        return 0;
    }
    for (int i = 0; i < result.size(); i++)
    {

        cout << result[i] << '\n';
    }

    return 0;
}