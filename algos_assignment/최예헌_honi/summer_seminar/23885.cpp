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

ll n, m;
ll starti, startj, endi, endj;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m>>starti>>startj>>endi>>endj;
    
    if (starti == endi && startj == endj){
        cout<<"YES";
    }
    else if (n == 1 || m == 1){
        cout<<"NO";
    }
    else if (starti == endi){
        if (abs(startj-endj) % 2 == 0)
            cout<<"YES";
        
        else
            cout<<"NO";
    }
    else if (startj == endj){
        if (abs(starti-endi) % 2 == 0)
            cout<<"YES";
        
        else
            cout<<"NO";
    }
    else{
        if ((abs(starti-endi) + abs(startj-endj)) % 2 == 0)
            cout<<"YES";
        
        else
            cout<<"NO";
    }
    return 0;
}
