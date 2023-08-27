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

    int N;
    cin >> N;
    vector<char> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];
    string T = "";
    int left = 0, right = N - 1;
    while (left < right) {
        if (s[left] < s[right])
            T.push_back (s[left++]);
        else T.push_back (s[right--]);
    }
    T += s[left];
    for (int i = 0; i < T.size(); i++) {
        cout << T[i];
        if (i % 80 == 79) cout << "\n";
    }
    cout << "\n";
    return 0;
}
