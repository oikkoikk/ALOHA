//우선순위 큐를 사용해도 되지만, 최대 힙을 직접 구현해보았음
//pop과 push 원리 파악!
#include <iostream>
#include <vector>

using namespace std;

vector<int> heap;
int N, comm;

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void push(int newVal) //최대 힙에 값 추가
{
    heap.push_back(newVal);

    int idx = heap.size() - 1; //루트 노드 인덱스가 0이므로
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx])
    {
        //현재 노드보다, 부모 노드가 더 작을 경우, swap!
        //최대 힙 구조가 성립할 때까지 반복
        swap(heap[(idx - 1) / 2], heap[idx]);
        idx = (idx - 1) / 2;
    }
}

void pop()
{
    //힙의 마지막 노드를 루트 노드에 덮어 씌운다.
    heap[0] = heap.back();
    heap.pop_back();

    int here = 0;
    while (true)
    {
        //왼쪽 자식 노드, 오른쪽 자식 노드와 비교해가며 최대 힙 구조를 만족할 때까지 swap!
        int left = here * 2 + 1, right = here * 2 + 2;
        int next = here;
        //리프 노드까지 가면, break!
        if (left >= heap.size())
            break;

        if (heap[next] < heap[left])
            next = left;
        if (right < heap.size() && heap[next] < heap[right])
            next = right;
        //최대 힙 구조를 만족하면, break!
        if (next == here)
            break;
        swap(heap[here], heap[next]);
        here = next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> comm;

        if (comm == 0)
        {
            if (!heap.empty())
            {
                cout << heap.front() << '\n';
                pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else
        {
            push(comm);
        }
    }
}