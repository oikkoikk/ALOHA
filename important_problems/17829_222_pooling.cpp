#include <iostream>
#include <algorithm>

using namespace std;

int N;
int matrix[1024][1024];

void pooling(int start_x, int start_y, int N)
{
	if(N == 1)
	{
		cout << matrix[0][0];
		return;
	}
	
	for (int i = start_y; i < N - 1; i+=2)
	{
		for (int j = start_x; j < N - 1; j+=2)
		{
			int temp[4] = {matrix[i][j], matrix[i+1][j], matrix[i][j+1], matrix[i+1][j+1]};
			
			sort(temp, temp+4);
			matrix[i/2][j/2] = temp[2];
		}
	}
	
	pooling(start_x, start_y, N >> 1);
}

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	pooling(0,0,N);
	
	
}