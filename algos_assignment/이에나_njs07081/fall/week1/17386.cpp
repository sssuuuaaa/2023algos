#include <iostream>

using namespace std;
pair<float, float> p1;
pair<float, float> p2;
pair<float, float> p3;
pair<float, float> p4;

int ccw(pair<float, float> p1, pair<float, float> p2, pair<float, float> p3) {
  float s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
  s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

  if (s > 0)
    return 1;
  else if (s == 0)
    return 0;
  else
    return -1;
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
  
  if(p1p2 <=0 && p3p4 <= 0)
      cout << 1 <<endl;
  else
    cout<< 0 <<endl;
}
