#include <iostream>
#include <vector>

using namespace std;

int T,N;
long long profit, now_max;

int main()
{
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		
		vector<long long> share_price(N);
		profit = 0;
		now_max = 0;
		
		for(int i=0; i < N; i++)
		{
			long long temp;
			
			cin >> temp;
			share_price[i] = temp;
		}
	

		for(int i = N - 1; i >= 0; i--)
		{
			//뒤에서부터 돌면서 확인
			
			// 최고점보다 낮으면 미리 매수
			if(share_price[i] < now_max)
			{
				profit += now_max - share_price[i];
			}
			// 최고점에서 매도
			else if(share_price[i] > now_max)
			{
				now_max = share_price[i];
			}
		}

		cout << profit << endl;
	}
}