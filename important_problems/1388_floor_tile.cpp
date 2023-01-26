#include <iostream>
#include <queue>

using namespace std;

int N, M, ans;
char floors[50][51];
bool visited[50][50];

bool check_floor_size(int x, int y)
{
	return (0 <= x && x < M && 0 <= y && y < N && !visited[y][x]);
}

void BFS(int start_x, int start_y)
{
	queue<pair<int,int>> Q;
	
	Q.push({start_x, start_y});
	visited[start_y][start_x] = true;
	
	while(!Q.empty())
	{
		auto now = Q.front();
		Q.pop();
		
		if(floors[now.second][now.first] == '-')
		{
			if(check_floor_size(now.first+1, now.second) && floors[now.second][now.first+1] == '-')
			{
				Q.push({now.first+1, now.second});
				visited[now.second][now.first+1] = true;
			}
		}
		else
		{
			if(check_floor_size(now.first, now.second+1) && floors[now.second+1][now.first] == '|')
			{
				Q.push({now.first, now.second+1});
				visited[now.second+1][now.first] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
	{
		cin >> floors[i];
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(!visited[i][j])
			{
				BFS(j,i);
				ans++;
			}
		}
	}
	
	cout << ans;
}