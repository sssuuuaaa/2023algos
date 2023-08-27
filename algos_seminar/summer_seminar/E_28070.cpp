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
int prefix_sum[120021];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char tmp;
        pi start, end;
        cin >> start.X >> tmp >> start.Y;
        cin >> end.X >> tmp >> end.Y;
        int s = (start.X - 2000) * 12 + start.Y - 1;
        int e = (end.X - 2000) * 12 + end.Y - 1;
        prefix_sum[s]++;
        prefix_sum[e + 1]--;
    }
    int idx = 0;
    for (int i = 1; i <= (9999 - 2000) * 12 + 12; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + prefix_sum[i];
        if (prefix_sum[i] > prefix_sum[idx]) idx = i;
    }
    int year = idx / 12 + 2000;
    int month = idx % 12 + 1;
    cout << year << "-";
    if (month < 10) cout << "0" << month << "\n";
    else cout << month << "\n";
    return 0;
}
