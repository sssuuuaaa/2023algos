#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if (b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll k, n, arr[41], result, ele; 
    cin >> k >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    ele = arr[0];
    result=0;
    for (int i=1; i<n; i++){
        result = (ele*arr[i])/gcd(ele, arr[i]); // 최소 공배수 
        ele = result;
    }
    cout << result-k;
    
}
