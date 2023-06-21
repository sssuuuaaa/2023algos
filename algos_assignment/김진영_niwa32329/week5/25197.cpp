#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    cout << fixed << setprecision(20);
    cout << n * ~-n / 2. / k << '\n';
}
