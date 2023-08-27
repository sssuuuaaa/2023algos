#include <iostream>
#include <cstring>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int arr[100000];
int visited[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	while (N) {
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; i++) {
			int& x = arr[i];
			cin >> x;
			visited[x] = 1;
		}

		int g;
		int cnt = 0;
		for (int k = 1; k <= 100; k++) {
			if (visited[k]) {
				cnt++;
				continue;
			}
			g = arr[0];
			for (int i = 1; i < N; i++) {
				g = gcd(g, arr[i]);
				if (g == k) {
					visited[k] = 1;
					cnt++;
					break;
				}
				else if (g % k) g = arr[i];
			}
		}

		cout << cnt << '\n';
		cin >> N;
	}
}
