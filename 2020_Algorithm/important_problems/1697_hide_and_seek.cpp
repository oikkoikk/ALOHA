#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001; //인덱스 100000까지 :: +1까지 넣음
bool visit[MAX];
int N, M; //N    수빈이위치, M 동생위치

int BFS(int N, int M)
{
    int time = 0; //몇초만에 찾았는지 ?
    queue<int> Q;
    Q.push(N);

    while (1)
    {
        int size = Q.size();

        for (int i = 0; i < size; i++) //Q의 사이즈만큼! (초 단위마다 분기하기 위해!)
        {
            N = Q.front();
            Q.pop();

            if (N == M)
                return time;

            if (N > 0 && visit[N - 1] == false)
            {
                Q.push(N - 1);
                visit[N - 1] = true;
            }
            if (N < 100000 && visit[N + 1] == false)
            {
                Q.push(N + 1);
                visit[N + 1] = true;
            }
            if (N * 2 <= 100000 && visit[N * 2] == false)
            {
                Q.push(N * 2);
                visit[N * 2] = true;
            }
        }
        time++; //1초 증가
    }
}

int main()
{
    cin >> N >> M;

    cout << BFS(N, M);

    return 0;
}
