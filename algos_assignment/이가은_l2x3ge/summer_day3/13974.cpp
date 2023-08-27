#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    int A[5003] = { 0, }, S[5003] = { 0, };
    int DP[5003][5003] = { 0, }, K[5003][5003] = { 0, };
    cin >> T;

    while(T--) {
        cin >> N;
        // 초기화
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            S[i] = S[i - 1] + A[i];
            DP[i - 1][i] = 0;
            K[i - 1][i] = i;
        }
        for (int i = 1; i <= N; i++) {
            DP[i - 1][i] = 0;
            K[i - 1][i] = i;
        }
        for (int d = 2; d <= N; d++) {
            for (int i = 0; i + d <= N; i++) {
                int j = i + d;
                DP[i][j] = 1e9;
                for (int k = K[i][j - 1]; k <= K[i + 1][j]; k++) {
                    int v = DP[i][k] + DP[k][j] + (S[j] - S[i]);
                    if (DP[i][j] > v) {
                        DP[i][j] = v;
                        K[i][j] = k;
                    }
                }
            }
        }
        cout << DP[0][N] << "\n";
    }
}
