/* 모듈러 연산의 속성
1. (a + b) mod n = {(a mod n) + (b mod n)} mod n

2. (a - b) mod n = {(a mod n) - (b mod n)} mod n

3. (a * b) mod n = {(a mod n) * (b mod n)} mod n
*/
#include <iostream>
#include <string>

using namespace std;

const int MULTIPLY = 31;
const int M = 1234567891;

int L;
unsigned long long temp, hashF, R;
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    R = 1;
    cin >> L >> str;
    for (int i = 0; i < L; i++)
    {
        hashF = (hashF + (str[i] - 'a' + 1) * R) % M;
        R = (R * MULTIPLY) % M;
    }
    cout << hashF;

    return 0;
}