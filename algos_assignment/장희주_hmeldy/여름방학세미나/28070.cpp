#include <iostream>
#include <string>
using namespace std;
// XXXX-XX

int parse(string str) {
	int year = stoi(str.substr(0,4));
	int month = stoi(str.substr(5));
	return (year - 2000)*12 + month-1; 
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);
	int n, gunIn, gunOut;
	int prefix[1000000]={};
	string start, end;
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> start >> end;
		gunIn = parse(start);
		gunOut = parse(end);
		prefix[gunIn]++;
		prefix[gunOut + 1]--; 

	}

	int res = 0; // 가장 많은 거의 달 변환 변수 
	for (int i = 1; i <= (9999 - 2000) * 12 + 12; i++) {
		prefix[i] = prefix[i - 1] + prefix[i];
		if (prefix[i] > prefix[res]) res = i;
	}

	int finYear = res / 12 + 2000;
	int finMonth = res % 12 + 1; // 인덱스니까 1 더해주기 
	cout << finYear << "-";
	if (finMonth < 10) cout << 0 << finMonth;
	else cout << finMonth;
	return 0;
}
