#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using ll = long long;
	
	ll x, k;
	cin >> x >> k;
	ll ans = 0LL;

	for (ll x_mask=1, ans_mask=1; k>0; x_mask*=2) {
		if (!(x & x_mask)) {
			if (k & ans_mask) {
				ans += x_mask;
				k -= ans_mask;
			}

			ans_mask *= 2;
		}
	}

	cout << ans;

	return 0;
}
