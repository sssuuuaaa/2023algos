#include <iostream>
#include <string>
using namespace std;

int main() {
	int loop;
    cin >> loop;
	string str;

	int cnt = loop;
	for (int k = 0; k < loop; k++) {
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != str[i + 1]) {
				for (int j = i + 1; j < str.length(); j++) {
					if (str[i] == str[j]) {
						cnt--;
						goto END;
					}
				}
			}
		}
	END:;
	}
	cout << cnt;
    return 0;
}
