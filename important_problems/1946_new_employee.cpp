#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, cnt;

int main()
{
  cin >> T;

  while (T--)
  {
    cin >> N;

    cnt = 0;

    vector<pair<int, int>> applicants;

    for (int i = 0; i < N; i++)
    {
      int doc, inter;

      cin >> doc >> inter;
      applicants.push_back({doc, inter});
    }

    sort(applicants.begin(), applicants.end());

    int inter_comp = applicants.front().second;
    // 면접 순위를 비교하기 위해, 서류 1등의 면접 등수 저장

    for (int i = 0; i < applicants.size(); i++)
    {
      if (applicants[i].second <= inter_comp)
      {
        cnt++;
        inter_comp = applicants[i].second;
      }
    }
    cout << cnt << endl;
  }
}