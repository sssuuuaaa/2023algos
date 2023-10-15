#include <iostream>

using namespace std;

pair<long long, long long> p1;
pair<long long, long long> p2;
pair<long long, long long> p3;
pair<long long, long long> p4;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2,
        pair<long long, long long> p3) {
  long long s =
      p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
  s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

  if (s > 0)
    return 1;
  else if (s == 0)
    return 0;
  else
    return -1;
}

void coor()
{
	double px = (p1.first * p2.second - p1.second * p2.first) * (p3.first - p4.first) - (p1.first - p2.first) * (p3.first * p4.second - p3.second * p4.first);
	double py = (p1.first * p2.second - p1.second * p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first * p4.second - p3.second * p4.first);
	double p = (p1.first - p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first - p4.first);

	if (p == 0) // 평행
	{
		// 교점 하나
		if (p2 == p3 && p1 <= p3) 
      cout << p2.first << " " << p2.second << '\n';
		else if (p1 == p4 && p3 <= p1) 
      cout << p1.first << " " << p1.second << '\n';
	}
	else // 교차
	{
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(16);
		cout << x << " " << y;
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  float a, b;
  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;
  cin >> p4.first >> p4.second;

  int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  if (p1p2 == 0 && p3p4 == 0) {
    if (p1 > p2)
      swap(p1, p2);
    if (p3 > p4)
      swap(p3, p4);

    if (p3 <= p2 && p1 <= p4) {
      cout << 1 << endl;
      coor();
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }

  else if (p1p2 <= 0 && p3p4 <= 0){
    cout << 1 << endl;
    coor();
  }
    
  else
    cout << 0 << endl;
  return 0;
}
