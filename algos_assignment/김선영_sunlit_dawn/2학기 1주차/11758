#include <iostream>
using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main(){
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int result = CCW(x1, y1, x2, y2, x3, y3);

	if (result == 0) cout << 0 << "\n";
	else if (result > 0) cout << 1 << "\n";
	else cout << -1 << "\n";
}
