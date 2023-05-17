#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	

	while (true) {
		string S;
		cin >> S;

		if (!S.compare(".")) break;

		int N = S.size();
		// fail 배열 만들기 : fail배열이란 비교에 실패하면 어디로 돌아가야하는 지 알려주는 배열
		vector<int> fail(N);
		for (int i = 1, j = 0; i < N; i++) {
			while (j && S[i] != S[j])
				j = fail[j - 1];
			if (S[i] == S[j]) {
				fail[i] = ++j;
			}
		}
		int a = N - fail[N - 1]; // 주기(가장 짧은 것)
		if (N % a == 0)cout << N / a << "\n";
		else cout << "1\n";
	}

	return 0;
}
