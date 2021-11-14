#include <iostream>
#include <string>

using namespace std;

string good = "";
int N;

bool isOK(int len)
{
    string ext1;
    string ext2;
    int compLen = len / 2;
    for (int j = 1; j <= compLen; j++) //수열 길이의 절반의 횟수만큼 체크(1자리 수열 체크, 2자리 수열 체크, ...)
    {
        ext1.clear();
        ext2.clear();

        ext1 = good.substr(len - j, j);
        ext2 = good.substr(len - (j * 2), j);
        if (ext1 == ext2)
        {
            return false;
        }
    }
    return true;
}
void Backtracking(int len)
{

    if (len == N + 1)
    {
        cout << good;
        exit(0);
    }

    for (int i = 1; i <= 3; i++)
    {
        good += to_string(i);
        if (isOK(len))
        {
            Backtracking(len + 1);
            good.erase(len - 1); //백트래킹
        }
        else
        {
            good.erase(len - 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Backtracking(1);
    return 0;
}