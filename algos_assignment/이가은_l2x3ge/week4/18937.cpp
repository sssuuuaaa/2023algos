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
        grundy ^= p-2;
    }
    string tmp;
    cin >> tmp;
    if (tmp[0] == 'W')
        grundy ? cout << "Whiteking" : cout << "Blackking";
    else
        grundy ? cout << "Blackking" : cout << "Whiteking";
    return 0;
}
