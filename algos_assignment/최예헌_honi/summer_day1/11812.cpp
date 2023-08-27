#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 100005
#define INF 987654321

ll t, n, m;
ll result = 0;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>t;
    while (t--){
        ll q1, q2;
        
        cin>>q1>>q2;
        if (m == 1){
            cout<<abs(q1-q2)<<"\n";
            continue;
        }
        
        result = 0;
        while (q1 != q2){
            if (q1 > q2){
                q1 = (q1+m-2)/m;
                result++;
            }
            else{
                q2 = (q2+m-2)/m;
                result++;
            }
        }
        cout<<result<<"\n";
    }
}
