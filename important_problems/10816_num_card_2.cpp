//upper_bound - lower_bound = ����
//�迭�� ������������ ���ĵǾ��־�� ��!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> A;
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
    cout << (upper_bound(A.begin(),A.end(),num) - lower_bound(A.begin(),A.end(),num)) << ' ';
  }
}