/*
<빠른 거듭제곱 알고리즘> O(logN)
N이 홀수이면 A^N을 A * A^(N-1)로 바꾸고 A를 결과값에 곱한다
N이 짝수이면 A^N을 (A^2)^(N/2) 즉 A를 제곱하고 N을 2로 나눈다
N = 0 이면 종료
*/
#include <iostream>

using namespace std;

int N;
long long B;
int A[5][5];
int res[5][5];

void matrix_multi(int mat_f[][5], int mat_r[][5])
{
	int temp[5][5];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = 0;
			for(int k =0; k < N; k++)
			{
				temp[i][j] += (mat_f[i][k] * mat_r[k][j]);
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			mat_f[i][j] = temp[i][j];
		}
	}
}

int main()
{
	cin >> N >> B;
	
	for (int i = 0; i < N; i++)
	{
		res[i][i] = 1;
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	
	while(B > 0)
	{
		if(B % 2 == 1){
			matrix_multi(res,A);
			B -= 1;
		}
		else{
			matrix_multi(A,A);
			B /= 2;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
}