#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 505
#define INF 9876543210

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    ll t, k;
    ll arr[MAX];
    ll sum[MAX];
    ll dp[MAX][MAX];
        
    cin>>t;
    while (t--){
        cin>>k;
        for (int i=1; i<=k; i++){
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
        }
            
        for (int i=1;i<=k;i++){
            for (int j=1; j<= k-i; j++){
                dp[j][i+j] = INF;
                for (int p=j; p<i+j;p++){
                    dp[j][i+j] = min(dp[j][i+j],dp[j][p]+dp[p+1][i+j] + sum[i+j]-sum[j-1]);
                }
            }
        }
        cout<<dp[1][k]<<"\n";
    }
}
