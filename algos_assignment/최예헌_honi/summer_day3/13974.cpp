#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 1002
#define INF 9876543210

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll dp[5100][5100], k[5100][5100];
    int t, n;
    
    cin>>t;
    while (t--){
        cin>>n;
        
        vector<int> v(n+1), s(n+1);

        for(int i=1; i<=n; i++){
            cin >> v[i];
            s[i] = s[i-1] + v[i];
        }
        
        for(int i=1; i<=n; i++){
            dp[i-1][i] = 0;
            k[i-1][i] = i;
        }

        for(int m=2; m<=n; m++){
            for(int i=0; m+i<=n; i++){
                int j = i+m; dp[i][j] = 1e9+7;
                
                for(int tmp=k[i][j-1]; tmp<=k[i+1][j]; tmp++){
                    int now = dp[i][tmp] + dp[tmp][j] + s[j] - s[i];
                    
                    if(dp[i][j] > now){
                        dp[i][j] = now;
                        k[i][j] = tmp;
                    }
                }
            }
        }

        cout << dp[0][n] << "\n";
    }
    
}
