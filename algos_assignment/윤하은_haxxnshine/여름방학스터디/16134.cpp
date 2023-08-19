#include <stdio.h>
#define ll long long
#define MAX 4000001
const int MOD = 1e9+7;
int A[MAX] = {1}, B[MAX];

int pow(ll a, int b){
    ll result = 1;
    while (b){
        if (b & 1) result = result*a %MOD;
        b >>= 1;
        a = a*a %MOD;
    }
    return result;
}
int main(){
    for (ll i = 1; i < MAX; i++)
        A[i] = A[i-1]*i %MOD;
    B[MAX-1] = pow(A[MAX-1], MOD-2);
    for (ll i = MAX-2; i >= 0; i--)
        B[i] = B[i+1]*(i+1) %MOD;
		
    int M;
    scanf("%d", &M);
    while (M--){
        int N, K;
        scanf("%d %d", &N, &K);
        printf("%d\n", ((ll)A[N]*B[K] %MOD) *B[N-K] %MOD);
    }
}
