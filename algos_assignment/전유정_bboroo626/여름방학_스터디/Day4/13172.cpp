#include <iostream>
#define MOD 1000000007
using namespace std;

// n^m을 구하는 함수
// 분할 정복을 이용한 거듭제곱 ★
long long power(long long n, long long m) {
	long long ret = 1;
	while (m) {
		if (m & 1) ret = ret * n % MOD;
		m = m / 2;
		n = n * n % MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int M;
	long long ans = 0;
	cin >> M;

	for (int i = 0; i < M; i++) {
		long long N, S;
		cin >> N >> S;

		// S/N = S * N^(1,000,000,007 - 2) mod 1,000,000,007
		ans += (S * (power(N, MOD - 2))) % MOD;
	}

	cout << ans % MOD;

	return 0;
}

// https://uigwonblog.tistory.com/13
