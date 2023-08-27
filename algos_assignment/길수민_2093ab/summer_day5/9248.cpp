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

char str[MAX];
int t, n, g[MAX], tg[MAX], SA[MAX], RANK[MAX], LCP[MAX];

bool cmp (int x, int y) {
    if (g[x] == g[y]) return g[x + t] < g[y + t];
    return g[x] < g[y];
}

void getSA (const char* str) {
    t = 1;
    n = (int) strlen (str);

    for (int i = 0; i < n; i++) {
        SA[i] = i;
        g[i] = str[i] - 'a';
    }

    while (t <= n) {
        g[n] = -1;
        sort (SA, SA + n, cmp);
        tg[SA[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (cmp(SA[i - 1], SA[i])) tg[SA[i]] = tg[SA[i - 1]] + 1;
            else tg[SA[i]] = tg[SA[i - 1]];
        }

        for (int i = 0; i < n; i++) g[i] = tg[i];
        t <<= 1;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> str;
    getSA (str);
    for (int i = 0; i < n; i++)
        cout << SA[i] + 1 << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) RANK[SA[i]] = i;

    int len = 0;
    for (int i = 0; i < n; i++) {
        int k = RANK[i];
        if (k) {
            int j = SA[k - 1];

            while (str[j + len] == str[i + len]) len++;

            LCP[k] = len;

            if (len) len--;
        }
    }
    cout << "x ";
    for (int i = 1; i < n; i++) cout << LCP[i] << " ";
    cout << "\n";
    return 0;
}
