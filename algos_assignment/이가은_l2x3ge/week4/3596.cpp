#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    bool visited[2002];
    int g[2002] = { 0, };
    g[1] = g[2] = g[3] = 1;

    for (int i = 4; i <= 2000; i++) {
        memset(visited, false, sizeof(bool) * 2002);
        for (int j = 0; j < (i+1)/2; j++) {
            // right ^ left
            int tmp = g[i-j-3] ^ (j>2 ? g[j-2] : 0);
            visited[tmp] = true;
        }
        for (int j = 0; j <= 2000; j++) {
            if (!visited[j]) {
                g[i] = j;
                break;
            }
        }
    }

    cin >> n;
    g[n] ? cout << "1": cout << "2";
    return 0;
}
