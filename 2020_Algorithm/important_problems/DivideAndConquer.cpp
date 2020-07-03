// �������� ������ ^_________^
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, number, sorted[500013];
vector<int> vec;

void merge(int start, int mid, int end)
{
    int i = start;   //ù ��° �迭 ���� idx
    int j = mid + 1; //�� ��° �迭 ���� idx
    int k = start;   //sorted�� ������ �� ���� idx

    while (i <= mid && j <= end)
    {
        if (vec[i] <= vec[j])
        {
            sorted[k] = vec[i];
            i++;
        }
        else
        {
            sorted[k] = vec[j];
            j++;
        }
        k++;
    }
    if (i > mid) //ù ��° �迭�� ���������� ��
    {
        for (int t = j; t <= end; t++)
        {
            sorted[k] = vec[t]; //�� ��° �迭 ���� ��� �״�� �ֱ�
            k++;
        }
    }
    else //�� ��° �迭�� ���������� ��
    {
        for (int t = i; t <= mid; t++)
        {
            sorted[k] = vec[t]; //ù ��° �迭 ���� ��� �״�� �ֱ�
            k++;
        }
    }
    for (int t = start; t <= end; t++)
    {
        vec[t] = sorted[t]; //���� conquer�� ���� sorted�� �� vec�� ����
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        vec.push_back(number);
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << sorted[i];
    }
}