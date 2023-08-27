#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 10002
#define INF 987654321
const ll mod=200002;

int n;
string str;

bool solve(int mid){
    ll hash=0;
    ll pw=1;
    
    for (int i=0;i<mid;i++){
        hash = (hash*26+str[i])%mod;
        pw = (pw*26)%mod;
    }
    
    vector <ll> v[mod];
    v[hash].push_back(0);
    
    for (int i=1;i<n-mid+1;i++){
        hash = (hash*26%mod - pw*str[i-1]%mod + str[i-1+mid] + mod)%mod;
        
        for (ll j=0;j<v[hash].size();j++){
            if (!strncmp(&str[v[hash][j]],&str[i],mid))
                return true;
        }
        v[hash].push_back(i);
    }
    return false;
}


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>str;
        
    ll l=0;
    ll r=str.size();
    ll result=0;
    while (l<=r){
        ll mid = (l+r)/2;
        
        if (solve(mid)){
            result = max(result,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<result;
}

