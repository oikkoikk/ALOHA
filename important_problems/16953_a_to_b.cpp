#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

long long A, B;
long long ans = LLONG_MAX;

bool BFS(long long A, long long B)
{
	queue <pair<long long,long long>> Q;
	
	Q.push({A*10 + 1, 1});
	Q.push({A*2,1});
	
	while(!Q.empty())
	{
		pair<long long,long long> num = Q.front();
		Q.pop();
		
		if(num.first < B)
		{
			Q.push({num.first*10+1,num.second+1});
			Q.push({num.first*2, num.second+1});
		}
		else if(num.first == B)
		{
			ans = min(ans, num.second);
			return true;
		}
	}
	
	return false;
}

int main()
{
	cin >> A >> B;
	
	cout << (BFS(A,B) ? ans+1 : -1);
}