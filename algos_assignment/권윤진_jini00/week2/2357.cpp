#include <iostream>
#include <math.h>

using namespace std;

int from;
long long maxarr[10000000];
long long minarr[10000000];

long long maximum(int left, int right, int idx = 1, int nodeLeft = 1, int nodeRight = from) {
    if (left > nodeRight || right < nodeLeft) {
        return -2000000000;
    }
    else if (left <= nodeLeft && right >= nodeRight) {
        return maxarr[idx];
    }
    int mid = (nodeLeft + nodeRight) / 2;
    
    return max(maximum(left, right, idx * 2, nodeLeft, mid), maximum(left, right, idx * 2 + 1, mid + 1, nodeRight));
}

long long minimum(int left, int right, int idx = 1, int nodeLeft = 1, int nodeRight = from) {
    if (left > nodeRight || right < nodeLeft) {
        return 2000000000;
    }
    else if (left <= nodeLeft && right >= nodeRight) {
        return minarr[idx];
    }
    int mid = (nodeLeft + nodeRight) / 2;
    
    return min(minimum(left, right, idx * 2, nodeLeft, mid), minimum(left, right, idx * 2 + 1, mid + 1, nodeRight));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    from = ((N & (N - 1)) == 0) ? pow(2, (int)log2(N)) : pow(2, (int)log2(N) + 1);
    
    for (int i = from; i < from + N; i++) {
        cin >> maxarr[i];
        minarr[i] = maxarr[i];
    }
    
    for (int i = from - 1; i >= 1; --i) {
        maxarr[i] = max(maxarr[i * 2], maxarr[i * 2 + 1]);
        minarr[i] = min(minarr[i * 2], minarr[i * 2 + 1]);
    }
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << minimum(a, b) << " " << maximum(a, b) << "\n";
    }
    
    return 0;
}
