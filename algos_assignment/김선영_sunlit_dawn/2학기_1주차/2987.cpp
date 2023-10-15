#include <iostream>
using namespace std;

int x1, x2, x3, y1, y2, y3;
int n;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

bool apple(int a, int b) {
  if (CCW(x1, y1, x2, y2, a, b) >= 0 && CCW(x2, y2, x3, y3, a, b) >= 0 && CCW(x3, y3, x1, y1, a, b) >= 0)
    return true;
  if (CCW(x1, y1, x2, y2, a, b) <= 0 && CCW(x2, y2, x3, y3, a, b) <= 0 && CCW(x3, y3, x1, y1, a, b) <= 0)
    return true;
  return false;
}

int main(){
    int a, b;
    int answer = 0;
    cin >> x1 >> y1;
	  cin >> x2 >> y2;
	  cin >> x3 >> y3;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      if (apple(a, b)) answer++;
    }
    
	  float s = abs((float)x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
    
    cout << fixed;
    cout.precision(1);
    cout << s << endl;
    
    cout.unsetf(ios::fixed);
    cout << answer <<endl;
    
    return 0;
}
