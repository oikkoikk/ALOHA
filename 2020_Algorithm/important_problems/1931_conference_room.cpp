//Greedy 알고리즘
//최대한 촘촘하게 채우는게 목표
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}
int main()
{
    int N;
    int last_conf = 0;
    int count = 1;
    cin >> N;
    vector<pair<int, int>> conference;
    for (int i = 0; i < N; i++)
    {
        int srt, fin;

        cin >> srt >> fin;
        conference.push_back(make_pair(srt, fin)); //일찍 끝나는 순으로 회의 정렬.(끝나는 시간 동일하면, 일찍 시작하는 회의 순으로.)
    }
    sort(conference.begin(), conference.end(), comp);
    for (int i = 1; i < N; i++) //첫번째 회의는 무조건 포함되어야 함.
    {
        if (conference[i].first >= conference[last_conf].second) //회의시간이 안 겹치면
        {
            count += 1;
            last_conf = i;
        }
    }
    cout << count;
}