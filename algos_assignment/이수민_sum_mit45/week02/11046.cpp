#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int N,M; //수열의 크기, M번 반복
int arr[2000001];
int A[2000001];


void manachers(){
    int r=0, p=0;
    
    for(int i=0; i<N; i++){
        if(i<=r) A[i] = min(A[2*p-i], r-i);
        else A[i] = 0;

        while(i-A[i]-1 >=0 && i+A[i]+1 <= N-1 && arr[i-A[i]-1] == arr[i+A[i]+1])
            A[i]++;
        
        if(r<i+A[i]){
            r=i+A[i];
            p=i;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        arr[i*2]=0; //짝수 팰린드롬 위해서
        cin >> arr[i*2+1];
    }
    N=N*2+1;
    arr[N-1]=0;
    
    manachers();
    
    cin >> M;
    while(M>0){
        int s,e; cin >> s >> e;
        s--; e--;
        
        if (A[s+e+1] >= e-s+1) cout << 1 << "\n";
        else cout << 0 << "\n";
        M--;
    }
       
    return 0;
}
