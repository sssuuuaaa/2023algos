#include <iostream>
#include <string>
using namespace std;

int main() {
	int result = 0;
	int N; 
	cin >> N;
	for (int i = 0; i < N; i += 1) {
		string str; 
		cin >> str;
		int size = str.length();
		int num = 0;
		size -= 2;
		for (int i = 0; i < size; i+=1) if (str.substr(i, 3) == "for") num+=1;
		size -= 2;
		for (int i = 0; i < size; i+=1) if (str.substr(i, 5) == "while") num+=1;

		result = max(result, num);
	}

	cout << result << endl;
}
