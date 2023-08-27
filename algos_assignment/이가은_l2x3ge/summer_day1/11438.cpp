#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> adj[100001];
int depth[100001] = { 0, };
int fastPar[17][100001];
int maxLevel = 17;
int dh = -1;

void dfs(int here, int prev);
void setFastPar();
int getLCA(int a, int b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	setFastPar();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << getLCA(a, b) << "\n";
	}
	
	return 0;
}

void dfs(int here, int prev) {
	depth[here] = depth[prev] + 1;
	//par[here] = prev;
	fastPar[0][here] = prev;

	for (int next : adj[here]) {
		if (next != prev)
			dfs(next, here);
	}
}

void setFastPar() {
	for (int level = 1; level < maxLevel; level++) {
		for (int i = 1; i <= n; i++) {
			fastPar[level][i] = fastPar[level - 1][fastPar[level - 1][i]];
		}
	}
}

int getLCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	dh = depth[b] - depth[a];

	/*while (dh) {
		b = par[b];
		dh--;
	}
	while (a != b) {
		a = par[a];
		b = par[b];
	}*/
	for (int lvl = maxLevel - 1; lvl >= 0; lvl--) {
		if ((1<<lvl) & dh) {
			b = fastPar[lvl][b];
		}
	}

	for (int lvl = maxLevel - 1; lvl >= 0; lvl--) {
		if (fastPar[lvl][a] != fastPar[lvl][b]) {
			a = fastPar[lvl][a];
			b = fastPar[lvl][b];
		}
	}

	if (a != b) a = fastPar[0][a];

	return a;
}
