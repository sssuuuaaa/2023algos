#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

string s;
char str[2000002];
int m[2000002];
int len;
int max_ = -1;

void manacher() {
	int r = -1, c = -1;
	for (int i = 0; i < len; i++) {
		//set value
		if (i <= r)
			m[i] = min(r - i, m[2 * c - i]);
		else
			m[i] = 0;
		
		//get palindrome longer
		while (i-m[i]-1 >= 0 && i+m[i]+1 < len && str[i-m[i]-1] == str[i+m[i]+1])
			m[i]++;

		//update
		if (r < i + m[i]) {
			r = i + m[i];
			c = i;
		}
		max_ = max(m[i], max_);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		str[i * 2] = '@';
		str[i * 2 + 1] = s[i];
	}
	str[s.size() * 2] = '@';
	len = s.size() * 2 + 2;
	manacher();
	cout << max_ << "\n";

	return 0;
}
