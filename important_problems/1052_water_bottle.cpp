#include <iostream>

using namespace std;

int N,K,bottle_cnt;

int beat_cnt(int n)
{
	if(n == 1)
		return 1;
	
	return n % 2 + beat_cnt(n/2);
}

int main()
{
	cin >> N >> K;
	
	//비트마스킹으로 1의 개수 카운팅하면 -> 가지고 있는 물병만으로 만들 수 있는 최소 물병 개수 파악 가능 => k와 비교
	
	bottle_cnt = beat_cnt(N);
	
	if(bottle_cnt <= K)
	{
		cout << 0;
	}
	else
	{
		//만약 구입해야 한다면, 크기를 키워가면서 비트에서 1의 개수가 bottle_cnt보다 적어지는 가장 작은 값을 찾아낸다
		int min_square_num = 1;
		while(min_square_num < N)
		{
			min_square_num <<= 1;
		}
		
		int min_num = N + 1;
		
		while(min_num <= min_square_num)
		{
			bottle_cnt = beat_cnt(min_num);
			if(bottle_cnt <=K)
			{
				break;
			}
			min_num++;
		}
		
		cout << min_num - N;
	}
}