#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	if (b == 1 || a == 1){
		if (c == e && d == f)
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}

	if ((c + d) % 2 == (e + f) % 2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
