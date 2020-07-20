/*
  삽입할 때는 2개의 우선순위 큐에 모두 삽입한다.
  삭제할 경우에는 삭제할 수 있는지 판단한 후 삭제를 한다.
  그 판단은 visited와 같은 배열을 통해서 할 수 있다.
  그 후, 다음 처리를 위해 2개의 큐의 동기화 작업을 한다.
*/
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1'000'001;
int N;
bool visited[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    while (T--)
    {
        cin >> N;

        priority_queue<pair<int, int>> maxHeap;                                                  //내림차순
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; //오름차순

        for (int i = 0; i < N; i++)
        {
            char op;
            int num;

            cin >> op >> num;

            if (op == 'I')
            {
                maxHeap.push({num, i});
                minHeap.push({num, i});
                visited[i] = true;
            }
            else
            {
                if (num == 1) //최댓값 제거
                {
                    //minHeap과 동기화
                    while (!maxHeap.empty() && !visited[maxHeap.top().second])
                    {
                        maxHeap.pop();
                    }
                    if (!maxHeap.empty())
                    {
                        //pop하므로 유효하지 않다고 표시
                        visited[maxHeap.top().second] = false;
                        maxHeap.pop();
                    }
                }
                else //최솟값 제거
                {
                    //maxHeap과 동기화
                    while (!minHeap.empty() && !visited[minHeap.top().second])
                    {
                        minHeap.pop();
                    }
                    if (!minHeap.empty())
                    {
                        //pop하므로 유효하지 않다고 표시
                        visited[minHeap.top().second] = false;
                        minHeap.pop();
                    }
                }
            }
        }
        //동기화
        while (!maxHeap.empty() && !visited[maxHeap.top().second])
        {
            maxHeap.pop();
        }
        while (!minHeap.empty() && !visited[minHeap.top().second])
        {
            minHeap.pop();
        }

        if (minHeap.empty() && maxHeap.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
        }
    }

    return 0;