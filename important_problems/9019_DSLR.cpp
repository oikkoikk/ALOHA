#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T;

void BFS(int start, int end)
{
  queue<pair<int, string>> Q;
  bool visited[10000] = {
      0,
  };
  pair<int, string> now;

  visited[start] = true;
  Q.push({start, ""});

  while (!Q.empty())
  {
    int temp;

    now = Q.front();
    int num = now.first;
    string str = now.second;

    Q.pop();

    if (num == end)
    {
      cout << str << '\n';
      return;
    }
    // D
    temp = (num * 2) % 10000;
    if (!visited[temp])
    {
      visited[temp] = true;
      Q.push({temp, str + 'D'});
    }
    // S
    temp = num == 0 ? 9999 : num - 1;
    if (!visited[temp])
    {
      visited[temp] = true;
      Q.push({temp, str + 'S'});
    }
    // L
    temp = (num % 1000) * 10 + (num / 1000);
    if (!visited[temp])
    {
      visited[temp] = true;
      Q.push({temp, str + 'L'});
    }
    // R
    temp = (now.first % 10) * 1000 + (now.first / 10);
    if (!visited[temp])
    {
      visited[temp] = true;
      Q.push({temp, str + 'R'});
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--)
  {
    int A, B;

    cin >> A >> B;

    BFS(A, B);
  }
}