//Huffman code(허프만 코드)
//가장 작은 2개를 골라서 합치는 과정을 반복!
//우선순위 큐(힙 구조) 사용
#include <iostream>
#include <queue>

using namespace std;

int N, temp, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    priority_queue<int,vector<int>,greater<int>> PQ; //오름차순 정렬로!

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        PQ.push(temp);
    }
    if(N == 1) //N이 1이면 비교할 수 없으므로, 0 출력!
    {
        cout << 0;
        return 0;
    }
    while(PQ.size()>=2)
    {
        temp = 0;
        for (int i = 0; i < 2; i++)
        {
            temp+= PQ.top(); //제일 작은 2개 더해서 
            PQ.pop();
        }
        PQ.push(temp);
        cnt+= temp;
    }
    cout << cnt;
    return 0;
}