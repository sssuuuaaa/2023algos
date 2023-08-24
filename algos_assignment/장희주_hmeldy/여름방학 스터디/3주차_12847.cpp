#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    long long ans = 0;
    int arr[100001];
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i > m) {
            sum = sum - arr[i - m];
        }
        sum = sum + arr[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
