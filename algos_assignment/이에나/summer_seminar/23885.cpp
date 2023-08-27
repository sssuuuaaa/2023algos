#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, sx, sy, ex, ey; cin >> N >> M >> sx >> sy >> ex >> ey;
	if (sx == ex && sy == ey) cout << "YES";
	else if (N == 1 || M == 1) cout << "NO";
	else if ((sx + sy + ex + ey) & 1) cout << "NO";
	else cout << "YES";
}
