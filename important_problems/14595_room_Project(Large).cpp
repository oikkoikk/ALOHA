//Union-Find 응용 버전

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1'000'000;
int N, M, a, b;
vector<int> parent(MAX + 1);
int count;

int Find(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = Find(parent[node]);
}

void Union(int smaller, int bigger) //번호가 큰 방이 root를 맡도록!
{
    int rootSmaller = Find(smaller); //시작 번호의 루트
    int rootBigger = Find(bigger);   //도착 번호의 루트

    if (rootSmaller != rootBigger) //벽뚫각 나오면
    {
        for (int i = rootSmaller; i < rootBigger; i = Find(i + 1)) //시작부터 도착까지 벽 뚫기 (Find 방식으로 해야 중복이 방지됨)
        {
            parent[i] = rootBigger; //번호 큰 방으로 root 설정
            count--;                //뚫은 벽만큼 방 개수 감소
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= MAX; i++)
    {
        parent[i] = i;
    }
    count = N;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        Union(a, b);
    }
    cout << count;

    return 0;
}