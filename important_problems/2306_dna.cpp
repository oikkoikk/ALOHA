//다이나믹 프로그래밍!
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> DNA;
string DNAstring;
int strLength;
int DP[501][501];

int main()
{
    cin >> DNAstring;

    strLength = DNAstring.length();
    for (int i = 0; i < strLength; i++)
    {
        DNA.push_back(DNAstring[i]);
    }

    //DP갱신
    for (int nowLen = 1; nowLen < strLength; nowLen++) //2글자부터 주우우욱
    {
        for (int start = 0; start + nowLen < strLength; start++) //시작 인덱스
        {
            int end = start + nowLen; //끝 인덱스

            //2번 조건 체크
            if ((DNA[start] == 'a' && DNA[end] == 't') || (DNA[start] == 'g' && DNA[end] == 'c'))
            {
                DP[start][end] = DP[start + 1][end - 1] + 2; //바깥쪽을 둘러싸고 있으므로!
            }
            //3번 조건 체크
            for (int mid = start; mid < end; mid++)
            {
                int merge = DP[start][mid] + DP[mid + 1][end];

                DP[start][end] = max(DP[start][end], merge); //KOI끼리 붙어있다면 갱신!
            }
        }
    }

    cout << DP[0][strLength - 1];

    return 0;
}