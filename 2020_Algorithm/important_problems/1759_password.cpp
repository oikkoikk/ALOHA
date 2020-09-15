#include <iostream>
#include <vector>
#include <algorithm> //vec을 오름차순으로!
using namespace std;

int L, C;
vector <char> vec;
char sampleC[15];
const int MAX = 15;
int solution [MAX];
int ans = 0;

bool isOK()
{
    int conso = 0, vowel = 0;

    for(int i=0; i<L; i++)
    {
        if(sampleC[i] == 'a' || sampleC[i] == 'e' ||sampleC[i] == 'i' || sampleC[i] == 'o' || sampleC[i] == 'u')
        {
            vowel ++;
        }
        else
        {
            conso ++;
        }
    }
    if(conso >=2 && vowel >=1)
    {
        return true;
    }
    return false;
}
int Backtracking(int depth, int select)
{
    if (depth == L)
    {
        if(isOK())
        {
            for(int i=0; i<L; i++)
            {
                cout << sampleC[i];
            }
            cout << '\n';
        }
    }
    
    for(int i=select; i<C; i++)
    {
        if(select == 0 && i>C-L)
        {
            exit(0);
        }
        sampleC[depth] = vec[i];
        Backtracking(depth+1, i+1); // 알파벳 중복 선택 안되도록 i+1을 인자로 넘김
    }

    return 0;
}
int main()
{
    cin  >> L >> C;

    for(int i=0; i<C; i++)
    {
        char ch;

        cin >> ch;
        vec.push_back(ch);
    }
    sort(vec.begin(), vec.end());

    Backtracking(0,0);

}
