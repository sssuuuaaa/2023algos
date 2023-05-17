#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> ans;
	string P, T;
	getline(cin, T);
	getline(cin, P);

	int n = T.length();
	int m = P.length();

	// fail 배열 만들기 : fail배열이란 비교에 실패하면 어디로 돌아가야하는 지 알려주는 배열
	vector<int> fail(m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j && P[i] != P[j])
			j = fail[j - 1];
		if (P[i] == P[j])
			fail[i] = ++j;
	}
	// 문자열 매칭
	for (int i = 0, j = 0; i < n; i++) {
		while (j && T[i] != P[j])
			j = fail[j - 1];
		if (T[i] == P[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = fail[j];
			}
			else
				j++;
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}

	return 0;
}
