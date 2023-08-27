#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 10002
#define INF 987654321

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    pair<int, int> p1, p2, p3;
    int x1, y1, x2, y2;
    
    cin>>p1.first>>p1.second;
    cin>>p2.first>>p2.second;
    cin>>p3.first>>p3.second;
    
    x1 = p2.first - p1.first;
    x2 = p3.first - p1.first;
    y1 = p2.second - p1.second;
    y2 = p3.second - p1.second;
    
    int result = (x1*y2) - (x2*y1);
    if (result > 0)
        cout<<"1";
    else if (result == 0)
        cout<<"0";
    else
        cout<<"-1";
    
}
