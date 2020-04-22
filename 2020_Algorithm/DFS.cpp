#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10000;
vector<int> graph[MAX+1];
bool visited[MAX+1];

void DFS(int x) // main에서 처음 탐색할 정점 입력
{
    visited[x] = true; // 정점 x를 방문했으므로 true
    cout << x << ' ';
    for(int i=0; i<graph[x].size(); i++) //정점 x에 연결된 정점만큼
    {
        if(!visited[graph[x][i]]) //방문하지 않은 정점이면
        {
            DFS(graph[x][i]); //재귀함수 호출
        }
    }
}
int main()
{
    
}