#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long dist[100'000];
long long price[100'000];
long long expense;

int main()
{
	cin >> N;
	
	for (int i = 0; i < N - 1; i++)
	{
		cin >> dist[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		cin >> price[i];
	}
	
	long long now_price = price[0];
	
	for (int i = 0; i < N -1; i++)
	{
		now_price = min(now_price, price[i]);
		expense += now_price * dist[i];
	}
	cout << expense;
}