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
    
    int n, x, y;
    int result = 0;
    
    cin>>n>>x>>y;
    if (x != 1)
        result++;
    if (x != n)
        result++;
    if (y != 1)
        result++;
    if (y != n)
        result++;
    
    cout<<result;
    
    
}
