#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int N, M;
int arr[2000002];
int m[2000002];

void manacher() {
	int r = -1, c = -1;
	for (int i = 0; i < N; i++) {
		//set value
		if (i <= r)
			m[i] = min(r - i, m[2 * c - i]);
		else
			m[i] = 0;
		
		//get palindrome longer
		while (i-m[i]-1 >= 0 && i+m[i]+1 < N && arr[i-m[i]-1] == arr[i+m[i]+1])
			m[i]++;

		//update
		if (r < i + m[i]) {
			r = i + m[i];
			c = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i*2-1];
		arr[i*2] = 0;
	}
	N = N * 2 + 1;
	manacher();

	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		s--; e--;
		if (m[s+e+1] >= e-s+1) cout << "1\n";
		else cout << "0\n";
	}


	return 0;
}
