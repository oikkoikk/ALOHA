#include <iostream>
#include <vector>
#include <algorithm>

int n, number, sorted[500013];
long long swap = 0;
std::vector<int> vec;

void merge(int start, int mid, int end)
{
  int i = start;   //left의 시작 idx
  int j = mid + 1; //right의 시작 idx
  int k = start;   //sorted 배열에 저장할 시작 idx

  while (i <= mid && j <= end)
  {
    if (vec[i] <= vec[j])
      sorted[k++] = vec[i++];
    else
    {
      sorted[k++] = vec[j++];
      swap += (long long)(j - k); //버블 소트 방식에서의 swap 횟수 계산
    }
  }
  if (i > mid) //left 배열이 먼저 끝나버린다면
  {
    for (int t = j; t <= end; t++)
      sorted[k++] = vec[t]; //right에 남아있는 것들 그대로 복붙
  }
  else //right 배열이 먼저 끝나버린다면
  {
    for (int t = i; t <= mid; t++)
      sorted[k++] = vec[t]; //left에 남아있는 것들 그대로 복붙
  }
  for (int t = start; t <= end; t++)
  {
    vec[t] = sorted[t]; //sort된 내용을 vec에 반영!
  }
}
void merge_sort(int start, int end)
{
  if (start < end)
  {
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
  }
}

int main()
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    std::cin >> number;
    vec.push_back(number);
  }
  merge_sort(0, n - 1);
  std::cout << swap;
}