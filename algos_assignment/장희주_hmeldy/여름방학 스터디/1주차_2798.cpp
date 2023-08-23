#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, sum;
    int arr[101]={};
    sum=0;
    cin >> n >> m;
    
    for (int k=0; k<n; k++){
        cin >> arr[k];
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int k=j+1; k<n; k++){
                if (arr[i]+arr[j]+arr[k]<=m && arr[i]+arr[j]+arr[k] > sum)
                    sum = arr[i]+arr[j]+arr[k];
            }
        }    
    }
    cout << sum;
}
