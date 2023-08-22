#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
  
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
vector<pair<ll, int>> vec;
 
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		ll x, r; cin >> x >> r;
		vec.push_back({ x - r,-1 });
		vec.push_back({ x + r, 1 });
	}
	sort(vec.begin(), vec.end(), cmp);
 
	ll ans = 0; ll last = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (st.empty()) {
			st.push(stackItem(vec[i].first, 0));
			last = vec[i].first;
		}
		else if (vec[i].second == -1) {
			if (vec[i].first == last) {
				vector<stackItem> vec_tmp;
				stackItem tmp = st.top(); st.pop();
				if (tmp.state != -1) tmp.state = 1;
				st.push(tmp);
			}
			else {
				stackItem tmp = st.top(); st.pop();
				tmp.state = -1;
				st.push(tmp);
				last = vec[i].first;
			}
		}
		else if (vec[i].second == 1) {
			if (tmp.state == 1 && last == vec[i].first)
				ans += 2;
			else
				ans++;
 
			last = vec[i].first;
		}
	}
	cout << ans + 1 << "\n";
}
