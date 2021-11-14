//Backtracking!
#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v;

void DFS(int start, int idx, vector<int> &str)
{
    if (start + (k - idx) < 6) //뒤에 숫자를 채워넣을 수 없는 상황이라면 그냥 일찍이 포기!
    {
        return;
    }
    if (start == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << str[i] << ' ';
        }
        cout << '\n';
        return;
    }

    else
    {
        for (int i = idx; i < k; i++)
        {
            str.push_back(v[i]);
            DFS(start + 1, i + 1, str);
            str.pop_back();
        }
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);

    cin >> k;

    while (k != 0)
    {
        v.clear();

        for (int i = 0; i < k; i++)
        {
            int num;
            cin >> num;

            v.push_back(num);
        }
        vector<int> str;
        DFS(0, 0, str);
        cout << '\n';
        cin >> k;
    }
}