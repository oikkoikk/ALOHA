#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int T;

int main()
{
  cin >> T;

  while (T--)
  {
    int N;
    bool is_reversed = false;
    string p, elem;
    string temp = "";
    deque<int> deq;

    cin >> p;
    cin >> N;
    cin >> elem;

    for (auto &cha : elem)
    {
      if (cha == '[')
        continue;
      else if (cha == ',' || cha == ']')
      {
        if (temp.length())
          deq.push_back(stoi(temp));
        temp = "";
      }
      else
        temp.push_back(cha);
    }

    for (auto &cha : p)
    {
      if (cha == 'R')
        is_reversed = !is_reversed;
      else if (cha == 'D')
      {
        if (deq.empty())
        {
          cout << "error" << endl;
          goto error_end;
        }

        if (is_reversed)
          deq.pop_back();
        else
          deq.pop_front();
      }
    }
    if (!deq.empty())
    {
      cout << '[';
      if (is_reversed)
        reverse(deq.begin(), deq.end());
      for (int i = 0; i < deq.size(); i++)
      {
        cout << deq[i];
        if (i < deq.size() - 1)
          cout << ',';
      }

      cout << ']' << endl;
    }
    else
    {
      cout << "[]" << endl;
    }
  error_end:
    continue;
  }
}