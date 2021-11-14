//문자열 처리, stack idea!
#include <iostream>
#include <stack>
#include <string>

using namespace std;
//Help( I[m being held prisoner in a fortune cookie factory)].
//위와 같은 케이스를 판단하려면 stack으로 해야 순서 고려 가능!
string temp;
bool flag;

int main()
{

    while (true)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        getline(cin, temp);

        if (temp == ".")
        {
            break;
        }

        stack<char> judge;
        flag = false;

        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == '(' || temp[i] == '[')
            {
                judge.push(temp[i]);
            }
            else if (temp[i] == ')')
            {
                if (judge.empty() || judge.top() != '(')
                {
                    flag = true;
                    break;
                }
                else
                {
                    judge.pop();
                }
            }
            else if (temp[i] == ']')
            {
                if (judge.empty() || judge.top() != '[')
                {
                    flag = true;
                    break;
                }
                else
                {
                    judge.pop();
                }
            }
        }

        if (flag == false && judge.empty())
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}
