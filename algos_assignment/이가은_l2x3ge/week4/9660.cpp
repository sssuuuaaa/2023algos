#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;
	int tmp = n % 7;
	if (tmp == 0 || tmp == 2)cout << "CY";
	else cout << "SK";
	return 0;
}
