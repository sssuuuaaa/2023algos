#include <iostream>
#include<vector>
#include<queue>
#include <algorithm>
#define INF 9876543210
using namespace std;

void NetworkFlow(int start, int end);
vector<int> adj[500];
int c[52][52], f[52][52];
int visit[52];

int n, result = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		int ca;
		cin >> a >> b >> ca;
		
		// character 전처리
		if (a > 90) a = a - 'a' + 26;
		else a = a - 'A';

		if (b > 90) b = b - 'a' + 26;
		else b = b - 'A';

		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] += ca;
		c[b][a] += ca;
	}
	NetworkFlow(0, 25);
	cout << result;
}

void NetworkFlow(int start, int end) {
	while (1) {
		fill(visit, visit + 52, -1);

		// BFS
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < adj[x].size(); i++) {
				int y = adj[x][i];
				// 방문하지 않은 노드 중, 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && visit[y] == -1) {
					q.push(y);
					visit[y] = x;
					if (y == end) break;
				}
			}
		}

		// 종결
		if (visit[end] == -1) break;

		// 유량 구하기
		int flow = INF;

		for (int i = end; i != start; i = visit[i])
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);

		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}
		result += flow;
	}
}
