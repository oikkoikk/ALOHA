//queue를 이용한 위상정렬 + 최적화 과정까지!

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, A, B;
vector<int> Node[32'001];
vector<int> Indegree(32'001,0);
vector<int> ans;
queue<int> QQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;

		Node[A].push_back(B);
		Indegree[B]++; //진입 간선 갯수 체크!(최적화)
	}
	for (int i = 1; i <= N; i++)
	{
		if(Indegree[i]==0) //진입 간선 없으면 큐에 추가!
		{
			QQ.push(i);
		}
	}
	while(!QQ.empty())
	{
		int curr = QQ.front();
		QQ.pop();

		ans.push_back(curr);
		for(auto next : Node[curr])
		{
			Indegree[next] -= 1; //현재 노드 제거 및 진출 간선 제거!
			if(Indegree[next] == 0) // 또 진입 간선 없으면 큐에 추가! 
			{
				QQ.push(next);
			}
		}
	}
	for(int data : ans)
	{
		cout << data << ' ';
	}
}