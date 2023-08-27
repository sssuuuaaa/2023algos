#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str;
    int n;
    int a, b;
    int parent[2001];
    int arr[4010];
    int check[2001];

    cin >> n;
    cin >> str;
    cin >> a >> b;

    int p = 0;
    int child = 1;

    for (int i = 1; i <= n * 2; i++) {
        if (str[i - 1] == '0') {
            parent[child] = p;
            arr[i] = child;
            p = child;
            child++;
        }
        else {
            arr[i] = p;
            p = parent[p];
        }
    }

    int x = arr[a];
    int y = arr[b];

    while (x != 0) {
        check[x] = 1;
        x = parent[x];
    }

    while (!check[y]) {
        y = parent[y];
    }

    for (int i = 1; i <= n * 2; i++) {
        if (arr[i] == y)
            cout << i << " ";
    }
}
