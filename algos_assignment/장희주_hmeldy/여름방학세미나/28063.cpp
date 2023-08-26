#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, y;
    cin >> n;
    cin >> x >> y;
    
    if (n==1) cout << 0;
    else if (n==2 || (x==1 && y==1) || (x==n && y==1) || 
             (x==1 && y==n) || (x==n && y==n)) cout << 2;
    else if (x==1 || y==1 || y==n || x==n) cout << 3;
    else cout << 4;
    
    return 0;
}
