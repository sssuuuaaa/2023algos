#include <iostream>

using namespace std;
int n;             //사과나무 개수
pair<float, float> p1; //삼각형 꼭짓점의 좌표
pair<float, float> p2;
pair<float, float> p3;

int ccw(pair<float, float> p1, pair<float, float> p2, float a, float b) {
  int s = p1.first * p2.second + p2.first * b + a * p1.second;
  s -= (p1.second * p2.first + p2.second * a + b * p1.first);

  if (s > 0)
    return 1;
  else if (s == 0)
    return 0;
  else
    return -1;
}

bool apple(float a, float b) {
  //cout << a << b <<endl;
  if (ccw(p1, p2, a, b) >= 0 && ccw(p2, p3, a, b) >= 0 && ccw(p3, p1, a, b) >= 0)
    return true;
  if (ccw(p1, p2, a, b) <= 0 && ccw(p2, p3, a, b) <= 0 && ccw(p3, p1, a, b) <= 0)
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int answer = 0;
  float a, b;
  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;
  cin >> n;

  //삼각형 면적
  float s = ((float)p1.first * (p2.second - p3.second) +
             p2.first * (p3.second - p1.second) +
             p3.first * (p1.second - p2.second)) /
            2;
  if (s < 0)
    s *= (-1);

  //백준이의 사과나무 개수
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (apple(a, b))
      answer++;
  }
  
  cout << fixed;
  cout.precision(1);
  cout << s << endl;
  
  cout.unsetf(ios::fixed);
  cout << answer <<endl;
  return 0;
}
