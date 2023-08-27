#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dp[505][505], K[505][505];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        vector<int> prefix_sum (N + 1, 0);
        memset (dp, 0, sizeof (dp));
        memset (K, 0, sizeof (K));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            prefix_sum[i + 1] = prefix_sum[i] + arr[i];
            dp[i][i + 1] = 0;
            K[i][i + 1] = i + 1;
        }

        for (int d = 2; d <= N; d++) {
            for (int i = 0; i + d <= N; i++) {
                int j = i + d;
                dp[i][j] = INF;
                for (int k = K[i][j - 1]; k <= K[i + 1][j]; k++) {
                    int v = dp[i][k] + dp[k][j] + prefix_sum[j] - prefix_sum[i];
                    if (dp[i][j] > v) {
                        dp[i][j] = v;
                        K[i][j] = k;
                    }
                }
            }
        }
        cout << dp[0][N] << "\n";
    }
    return 0;
}
