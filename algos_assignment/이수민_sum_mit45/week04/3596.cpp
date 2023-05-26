#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dp(2001);
vector<bool> visited(100);


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    dp[1] = dp[2] = dp[3] = 1;
    
    for (int i = 4; i <= 2000; i++) {
        visited.assign(100, false);
        for (int j = 1; j <= (i + 1 >> 1); j++){
            int tmp = dp[i-j-2] ^ (j - 3 > 0 ? dp[j-3] : 0);
            visited[tmp] = true;
        }
        for (int j = 0; j < 100; j++) {
            if (!visited[j]) {
                dp[i] = j;
                break;
            }
        }
    }
    
    cin >> N;
    cout << (dp[N] ? 1 : 2);
    return 0;
}
