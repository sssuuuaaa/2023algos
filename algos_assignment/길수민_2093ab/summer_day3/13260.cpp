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
int N, M;
int dp[1010][1010], p[1010][1010];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    vector<int> input(M);
    vector<int> arr(M + 3);
    for (int i = 0; i < M; i++) cin >> input[i];
    sort (input.begin(), input.end());
    for (int i = 1; i < M + 1; i++) arr[i] = input[i - 1];
    input[M + 1] = N;
    for (int i = 1; i <= M + 1; i++) p[i - 1][i] = i;
    for (int i = M; i >= 0; i--) {
        for (int j = i + 2; j <= M + 1; j++) {
            dp[i][j] = INF;
            for (int k = p[i][j - 1]; k <= p[i + 1][j]; k++) {
                int val = dp[i][k] + dp[k][j];
                if (dp[i][j] > val) {
                    dp[i][j] = val;
                    p[i][j] = k;
                }
            }
            dp[i][j] += arr[j] - arr[i];
        }
    }
    cout << dp[0][M + 1] << "\n";
    return 0;
}
