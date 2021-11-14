//long long을 넘어가는 범위!
//따라서 string으로 하나하나씩 더해주며 진행
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 100 + 1;
int N, M;
string memo[MAX][MAX];

string string_add(const string_view num1, const string_view num2)
{
    long long sum = 0;
    //num을 copy에 복사하였다.
    string copy1(num1), copy2(num2);
    string ret;

    //copy1, copy2, sum이 모두 비어있을때까지 계산을 계속한다.
    while (!copy1.empty() || !copy2.empty() || sum)
    {
        if (!copy1.empty())
        {
            //copy1에 있는 마지막 문자는 char형태로 저장되어있으므로(ascii형식) '0'을 빼주어 정수화 해주었다.
            sum += copy1.back() - '0';
            copy1.pop_back();
        }
        if (!copy2.empty())
        {
            sum += copy2.back() - '0';
            copy2.pop_back();
        }
        //sum의 일의 자릿수를 ret에 넣어주자.(이때, char형으로 들어가므로 다시 '0'을 더해준다)
        ret.push_back((sum % 10) + '0');
        sum /= 10;
    }
    //역순으로 입력되어있으므로, reverse함수를 활용해 문자열을 뒤집는다.
    reverse(ret.begin(), ret.end());
    return ret;
}

//nCr = n-1Cr + n-1Cr-1
string Combination(int n, int r)
{
    if (n == r || r == 0)
        return memo[n][r] = "1";
    else if (r == 1)
        return memo[n][r] = to_string(n);
    else if (memo[n][r] != "")
        return memo[n][r];

    return memo[n][r] = string_add(Combination(n - 1, r - 1), Combination(n - 1, r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    cout << Combination(N, M);
}