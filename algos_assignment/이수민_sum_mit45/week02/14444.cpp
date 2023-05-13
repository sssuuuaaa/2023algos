#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

string s;
int A[200001];
char arr[200001];
//string news;

void manachers(int N){
    int r=0, p=0;
    
    for(int i=0; i<N; i++){
        if(i<=r) A[i] = min(A[2*p-i], r-i);
        else A[i] = 0;

        //cout << A[i] << " ";
        while(i-A[i]-1 >=0 && i+A[i]+1 < N && arr[i-A[i]-1] == arr[i+A[i]+1])
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
    
    cin>> s;
    int N=s.size();
    
    for(int i=0; i<s.size(); i++){
        arr[i*2]='#';
        arr[i*2+1] = s[i];
    }
    N=N*2+1;
    arr[N-1]='#';
    
    //for(int i=0; i<N; i++)
    //    cout << arr[i] << " ";
    manachers(N);
    
    int mmax=-1;
    for(int i=0; i<N; i++){
        if(A[i]>mmax) mmax=A[i];
    }
    cout << mmax;
    
    return 0;
}
