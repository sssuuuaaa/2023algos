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

    ll N;
    cin >> N;
    int K, Q;
    cin >> K >> Q;
    while (Q--) {
        ll x, y;
        cin >> x >> y;
        if (K == 1) cout << abs (x - y) << "\n";
        else {
            ll dist = 0;
            while (x != y) {
                while (x > y) {
                    x = (x + K - 2) / K;
                    dist++;
                }
                while (y > x) {
                    y = (y + K - 2) / K;
                    dist++;
                }
            }
            cout << dist << "\n";
        }
    }
    return 0;
}
