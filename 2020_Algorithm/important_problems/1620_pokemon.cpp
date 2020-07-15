#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string temp, keyWord;
vector<pair<int, string>> pokemon;
vector<pair<int, string>> pokemonSorted;

bool comp(const pair<int, string> &p1, const pair<int, string> &p2)
{
    return p1.second < p2.second;
}
void BinarySearch(int flag, string &key)
{
    int start, end, mid;
    start = 1;
    end = N;

    if (flag == 0) //숫자면
    {
        int num = stoi(key);
        while (start <= end)
        {
            mid = (start + end) / 2;

            if (pokemon[mid].first == num)
            {
                cout << pokemon[mid].second << '\n';
                return;
            }
            else if (pokemon[mid].first > num)
            {
                end = mid - 1;
                continue;
            }
            else
            {
                start = mid + 1;
                continue;
            }
        }
    }
    else
    {
        while (start <= end)
        {
            mid = (start + end) / 2;

            if (pokemonSorted[mid].second == key)
            {
                cout << pokemonSorted[mid].first << '\n';
                return;
            }
            else if (pokemonSorted[mid].second > key)
            {
                end = mid - 1;
                continue;
            }
            else
            {
                start = mid + 1;
                continue;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pokemon.push_back({0, ""}); //초기 설정
    pokemonSorted.push_back({0, ""});

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> temp;

        pokemon.push_back({i, temp});
        pokemonSorted.push_back({i, temp});
    }

    sort(pokemonSorted.begin() + 1, pokemonSorted.end(), comp); //0번째 항은 무시

    for (int i = 0; i < M; i++)
    {
        cin >> keyWord;
        if ('1' <= keyWord[0] && keyWord[0] <= '9') //숫자가 들어왔다면
        {
            BinarySearch(0, keyWord);
        }
        else //문자가 들어왔다면
        {
            BinarySearch(1, keyWord);
        }
    }
}