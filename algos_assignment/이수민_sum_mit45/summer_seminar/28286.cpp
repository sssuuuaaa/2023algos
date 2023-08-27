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

int n, k;
int omr[22] = {0,};
int sol[22] = {0,};
int result = 0;

void solve(int step) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (omr[i] == sol[i])
            cnt++;
    }
    result = max(result, cnt);
    if (step == k)
        return;
    
    for (int i = 0; i < n; i++) {
        int tmp = omr[i];
        
        for (int j = i + 1; j < n; j++) {
            omr[j - 1] = omr[j];
        }
        
        omr[n - 1] = 0;
        solve(step + 1);
        
        for (int j = n - 1; j > i; j--)
            omr[j] = omr[j - 1];
        omr[i] = tmp;
        tmp = omr[n - 1];
        
        for (int j = n; j > i; j--)
            omr[j] = omr[j - 1];
        omr[i] = 0;
        
        solve(step + 1);
        for (int j = i; j < n - 1; j ++)
            omr[j] = omr[j + 1];
        
        omr[n - 1] = tmp;
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>omr[i];
    
    for (int i=0; i<n; i++)
        cin>>sol[i];
    
    solve(0);
    cout<<result;
    
}
