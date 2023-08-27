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

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, x, y;
    cin >> N;
    cin >> x >> y;
    int ans = 0;
    if (x != 1) ans++;
    if (y != 1) ans++;
    if (x != N) ans++;
    if (y != N) ans++;
    cout << ans << "\n";
    return 0;
}
