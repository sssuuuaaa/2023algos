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
	else if (c < 0) return -1;
	else return 0;
}

bool isIntersect(pii p1, pii p2, pii p3, pii p4) {

    int p1p2 = CCW(p1, p2, p3) * CCW(p1, p2, p4); 
    int p3p4 = CCW(p3, p4, p1) * CCW(p3, p4, p2); 
    
    return p1p2 <= 0 && p3p4 <= 0;
}
int main(){
	cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;
    cin >> p4.first >> p4.second; 

	if (isIntersect(p1, p2, p3, p4)) cout << 1 << endl;
    else cout << 0 << endl;
		
}
	
