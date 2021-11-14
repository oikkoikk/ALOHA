//DFS로 트리의 지름 찾기
//임의의 한 지점 -> 최대지점 -> 최대지점
#include <iostream>
#include <vector>

using namespace std;

int N, startNode, endNode, weight, reStart;
vector<vector<pair<int, int>>> Tree;
vector<int> NodeWeight;
vector<bool> visited;
int weightMax = 0;

void DFS(int start, int depth)
{

    visited[start] = true;

    for (auto next : Tree[start])
    {
        if (!visited[next.first])
        {
            NodeWeight[next.first] = NodeWeight[start] + next.second;
            DFS(next.first, depth + 1);
        }
    }
    if (NodeWeight[start] > weightMax) //끝까지 탐색했는데
    {
        weightMax = NodeWeight[start]; //가중치 갱신 가능하면 갱신!
        reStart = start;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Tree.resize(N + 1); //초기화 작업
    NodeWeight.resize(N + 1, 0);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++)
    {
        cin >> startNode >> endNode >> weight;
        Tree[startNode].push_back({endNode, weight});
        Tree[endNode].push_back({startNode, weight});
    }

    DFS(1, 1);

    NodeWeight.clear(); //다시 한번 탐색하기 위한 초기화
    NodeWeight.resize(N + 1, 0);
    fill(visited.begin(), visited.end(), false);

    DFS(reStart, 1); //최대 지점에서 다시 DFS하면 트리의 지름 얻을 수 있다!

    cout << weightMax;
}