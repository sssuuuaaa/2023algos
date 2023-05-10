#include <iostream>
#include <cmath>
using namespace std;
double fact_log(double n) {
	int i = 1;
	double j = 1;
	while ((j *= ++i) <= n);
	return i - 1;
}
int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i += 1) {
		string S;
		double N, T, L;
		cin >> S >> N >> T >> L;
		bool possible = true;
		if (S == "O(N)" && N > L * 100000000 / T) possible = false;
		else if (S == "O(N^2)" && (N * N) > L * 100000000 / T) possible = false;
		else if (S == "O(N^3)" && (N * N * N) > L * 100000000 / T) possible = false;
		else if (S == "O(2^N)" && N >log2(L * 100000000 / T)) possible = false;
		else if (S == "O(N!)" && N > fact_log(L * 100000000 / T)) possible = false;
		
		cout << ((possible) ? "May Pass." : "TLE!") << endl;
	}
}
