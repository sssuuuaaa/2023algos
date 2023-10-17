#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
typedef pair<double, double>P;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (-y1 * x2 - y2 * x3 - y3 * x1);
	return res / 2;
}

int main() {
	int n; cin >> n;
	vector<P>arr(n);

	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &arr[i].first, &arr[i].second);

	double res = 0;
	for (int i = 1; i < n; i++) // 해당 문제는 한 점을 기준으로 반복문을 진행하며 ccw를 더해주면 된다.
		res += ccw(arr[0].first, arr[i - 1].first, arr[i].first, arr[0].second, arr[i - 1].second, arr[i].second);

  // a-b-c의 ccw를 구하고 a-c-d의 ccw를 더하게 되면 두 값은 서로 다른 부호를 갖게 된다.
  // ccw의 방향이 다르기 때문에 하나가 양수라면 다른 하나는 음수가 나오는 것

	printf("%.1lf", abs(res));
	return 0;
}

// 참고: https://ip99202.github.io/posts/%EB%B0%B1%EC%A4%80-2166-%EB%8B%A4%EA%B0%81%ED%98%95%EC%9D%98-%EB%A9%B4%EC%A0%81/
