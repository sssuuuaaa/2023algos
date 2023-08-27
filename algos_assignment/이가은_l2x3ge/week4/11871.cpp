#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p;
    cin >> n;

    int grundy = 0;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p % 2 == 0)
            grundy ^= (p - 2) / 2;
        else
            grundy ^= (p + 1) / 2;
    }

    grundy ? cout << "koosaga" : cout << "cubelover";
    return 0;
}

/* 짝수 돌 제거가능, 전체 돌 제거는 홀수일 때에만
g(0) = 0 base
g(1) = mex{g(0)} = 1
g(2) = 0 base
g(3) = mex{g(0),g(1)} = 2
g(4) = mex{g(2)} = 1
g(5)  = mex{g(0),g(1),g(3)} = 3
g(6) = mex{g(2),g(4)} = 2
g(7) = mex{g(0),g(1),g(3),g(5)} = 4

g(홀수n) = (n+1)/2
g(짝수n) = (n-2)/2
*/
