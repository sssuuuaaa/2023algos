#include <iostream>
using namespace std;

int n, m, s, e;
int num[2000001];
int arr[2000001];

void manacher() {
	int r = 0, p = 0; //r: 팰린드롬이 끝나는 지점

	for (int i = 0; i < n; i++) { //arr 초기값 설정
		if (i <= r) 
			arr[i] = min(r - i, arr[2 * p - i]);
			//p: 팰린드롬 중점의 인덱스, 2*p-i: 현재 속해있는 팰린드롬의 대칭점
		else 
			arr[i] = 0;

		//인덱스 값이 유효한가 && 펠린드롬 검사 
		while ((i - arr[i] - 1 >= 0 && i + arr[i] + 1 <= n - 1) 
			&& (num[i - arr[i] - 1] == num[i + arr[i] + 1])) 
			arr[i] += 1;

		if (r < i + arr[i]) { //update
			r = i + arr[i];
			p = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) { //"123"->"0102030"로 사이에 0을 끼워 입력
		num[i * 2] = 0;
		cin >> num[i * 2 + 1];
	}
	n = n * 2 + 1;
	num[n - 1] = 0;
	manacher();

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		s--; 
		e--;

		if (arr[s + e + 1] >= e - s + 1) //확장된 arr에 대해 인덱스 조절
			cout << "1\n"; //palindrom
		else 
			cout << "0\n"; //not palindrom
	}

	return 0;
}
