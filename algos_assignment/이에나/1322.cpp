#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int X, K, now, index;
long long ans;
int x[65], k[65];

int main() 
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> X >> K;

	index = 0;
	while (X >= 1)
	{
		if (X % 2 == 1) x[index] = 1;
		else x[index] = 0;
		X /= 2;
		index++;
	}

	index = 0;
	while (K >= 1)
	{
		if (K % 2 == 1) k[index] = 1;
		else k[index] = 0;
		K /= 2;
		index++;
	}

	for (int i = 0; i < 65; i++)
	{
		if (x[i] == 0)
		{
			if (k[now] == 1) ans += ((long long)1 << i);
			now++;
		}
	}
	cout << ans;
}
