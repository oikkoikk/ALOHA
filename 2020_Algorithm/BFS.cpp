#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 10000;
vector<int> graph[MAX+1];
queue<int> q;
bool visited[MAX+1];

void BFS(int start) //start = 처음 시작할 정점
{
    q.push(start);
    visited[start] = true; //큐에 넣고 방문 표시

    while(!q.empty()) //큐가 비어있지 않을 때(연결된 정점이 있을 때)
    {
        int curr = q.front(); //큐 맨 앞의 요소 = curr
        q.pop(); //방문하였으니 pop
        cout << curr << ' ';

        for(int i=0; i<graph[curr].size(); i++) //현재 정점에 연결된 정점 개수만큼
        {
            if(!visited[graph[curr][i]]) //방문하지 않았으면
            {
                q.push(graph[curr][i]); //큐에 push
                visited[graph[curr][i]] = true; //그 정점을 방문했다고 표시(매우 중요)
            }
        }
    }
}