//스택!
#include <iostream>
#include <string>
#include <stack>

using namespace std;
string str;
string result;
stack<char> stk;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        //알파벳은 바로바로 result에 추가!
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            result += str[i];
        }
        //연산자라면
        else
        {
            switch (str[i])
            {
            case '(':
                //괄호가 있으면 먼저 실행해야하므로 바로 스택에 넣는다!
                stk.push(str[i]);
                break;
            case '*':
            case '/':
                //우선순위 제일 높으므로 같은 기호들 pop
                while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
                {
                    result += stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
                break;
            case '+':
            case '-':
                //+/-보다 우선순위 같거나 높은 기호들 pop
                while (!stk.empty() && stk.top() != '(')
                {
                    result += stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
                break;
            case ')':
                //'('가 나올 때까지 다 pop
                while (!stk.empty() && stk.top() != '(')
                {
                    result += stk.top();
                    stk.pop();
                }
                //'(' pop
                stk.pop();
                break;
            }
        }
    }
    while (!stk.empty()) //다 돌고도 남은 것이 있다면 마지막에 추가!
    {
        result += stk.top();
        stk.pop();
    }
    cout << result;

    return 0;
}