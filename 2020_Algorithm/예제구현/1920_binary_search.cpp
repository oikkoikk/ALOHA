//이진탐색
//배열이 오름차순으로 정렬되어있어야 함!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int BinarySearch(int N, const int key)
{
  int start = 0;
  int end = N-1;
  int mid;

  while(start<=end)
  {
    mid = (start + end) /2;

    if(A[mid] == key)
    {
      cout << '1' << '\n';
      return 0;
    }
    else if(A[mid] > key)
    {
      end = mid - 1;
    }
    else
    {
      start = mid +1;
    }
  }
  cout << '0' << '\n';
  return 0;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N;
  for(int i=0; i<N; i++)
  {
    int num;
    cin >> num;
    A.push_back(num);
  }
  sort(A.begin(), A.end());
  cin >> M;
  for(int i=0; i<M; i++)
  {
    int num;
    cin >> num;
    BinarySearch(N, num);
  }
}