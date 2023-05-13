#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s, e;
int num[2001];
bool palindrom[2001][2001] = { false, };

int main(){
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		if (num[i] == num[i + 1])
			palindrom[i][i + 1] = true;
	}
	for (int i = 1; i <= n; i++) {
		palindrom[i][i] = true;
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (num[i] == num[j] && palindrom[i + 1][j - 1] == true) {
				palindrom[i][j] = true;
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << palindrom[s][e] << '\n';
	}

	return 0;
}
