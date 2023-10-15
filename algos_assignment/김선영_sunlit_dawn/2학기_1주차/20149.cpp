#include <iostream>
#define pii pair<int, int>
using namespace std;
pii p1;
pii p2;
pii p3;
pii p4;

int CCW(pii p1, pii p2, pii p3){
	int c = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
	
	if (c > 0) return 1;
	else if (c == 0) return 0;
	else return -1;
}

bool isIntersect(pii p1, pii p2, pii p3, pii p4) {
    int p1p2 = CCW(p1, p2, p3) * CCW(p1, p2, p4); 
    int p3p4 = CCW(p3, p4, p1) * CCW(p3, p4, p2); 

    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        return (p3 <= p2 && p1 <= p4); 
    }
    return (p1p2 <= 0 && p3p4 <= 0); 
}

void point(pii p1, pii p2, pii p3, pii p4){
    double px = (p1.first * p2.second - p1.second * p2.first) * (p3.first - p4.first) - (p1.first - p2.first) * (p3.first * p4.second - p3.second * p4.first);
	double py = (p1.first * p2.second - p1.second * p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first * p4.second - p3.second * p4.first);
	double p = (p1.first - p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first - p4.first);
    if (p == 0) {
     if (p2 == p3 && p1 <= p3) 
      cout << p2.first << " " << p2.second << '\n';
		else if (p1 == p4 && p3 <= p1) 
      cout << p1.first << " " << p1.second << '\n';
	}
	else {
		double x = px / p;
		double y = py / p;
		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

int main(){
	cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;
    cin >> p4.first >> p4.second;

    bool result = isIntersect(p1, p2, p3, p4);
    cout << result << endl;
    if (result) point(p1, p2, p3, p4);
}
