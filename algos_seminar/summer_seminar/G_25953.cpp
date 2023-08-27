#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e4 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dp[MAX][1001];
int n, t, m;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> n >> t >> m;
    int s, e;
    cin >> s >> e;
    for (int i = 0; i < n; i++)
        dp[i][0] = (i == s) ? 0 : INF;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
            dp[j][i + 1] = dp[j][i];
        for (int j = 0; j < m; j++)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            dp[u][i + 1] = min (dp[v][i] + cost, dp[u][i + 1]);
            dp[v][i + 1] = min (dp[u][i] + cost, dp[v][i + 1]);
        }
    }
    if (dp[e][t] == INF) cout << "-1\n";
    else cout << dp[e][t] << "\n";
    return 0;
}
