#include <iostream>

using namespace std;

int N, M, cnt;
int A[50][50];
int B[50][50];

void reverse(int start_y, int start_x)
{
	for (int i = start_y; i < start_y + 3; i++)
	{
		for(int j = start_x; j < start_x + 3; j++)
		{
			A[i][j] = !A[i][j];
		}
	}
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
				scanf("%1d", &A[i][j]);	
		}
	}
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
				scanf("%1d", &B[i][j]);	
		}
	}
	
	for (int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			//(0,0)은 첫 번째 턴밖에 기회가 없다. 결국엔 좌상단부터 하나씩 바꿔가면서 보는게 최적해!
			if(A[i][j] != B[i][j])
			{
				reverse(i,j);
				cnt++;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(A[i][j] != B[i][j])
			{
				cout << -1;
				exit(0);
			}
		}
	}
	
	cout << cnt;
	
	
	
}