#include <iostream>
#include <cstring>
 
#define endl "\n"
#define MAX 10010
using namespace std;
 
int N, M;
int Coin[25];
int DP[MAX];
 
void Initialize()
{
    memset(DP, 0, sizeof(DP));
}
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> Coin[i];
    cin >> M;
}
 
void Solution()
{
    DP[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = Coin[i]; j <= M; j++)
        {
            DP[j] = DP[j] + DP[j - Coin[i]];
        }
    }
    cout << DP[M] << endl;
}
 
void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
