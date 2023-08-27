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
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int prime[44];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    int K, N;
    cin >> K >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        int x = 2;
        int tmp = 0;
        while (num > 1) {
            tmp = 0;
            while (num % x == 0)
            {
                tmp++;
                num /= x;
            }
            prime[x] = max (prime[x], tmp);
            x++;
        }
    }
    ll ans = 1;
    for (int i = 1; i < 44; i++)
    {
        while (prime[i]) {
            prime[i]--;
            ans *= i;
        }
    }
    cout << ans - K << "\n";
    return 0;
}
