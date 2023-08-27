#include <iostream>
int main() {
	int n, x, y;
	std::cin >> n >> x >> y;
	if (n == 1) {
		std::cout << 0;
		return 0;
	}
	if(x == 1 || x == n || y == 1 || y == n)
		if (x * y == 1 || x * y == n * n || x * y == n) 
			std::cout << 2;
		else
			std::cout << 3;
	else
		std::cout << 4;
}
