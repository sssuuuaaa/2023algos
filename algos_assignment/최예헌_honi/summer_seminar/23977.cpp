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
    
    int k, n;
    int prime[44]={0,};
    
    cin>>k>>n;
    
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        int x = 2;
        int tmp = 0;
        while (num > 1) {
            tmp = 0;
            while (num % x == 0){
                tmp++;
                num /= x;
            }
            prime[x] = max (prime[x], tmp);
            x++;
        }
    }
        
    ll result = 1;
    for (int i = 1; i < 44; i++){
        while (prime[i]) {
            prime[i]--;
            result *= i;
        }
    }
    cout << result - k;
    
}
