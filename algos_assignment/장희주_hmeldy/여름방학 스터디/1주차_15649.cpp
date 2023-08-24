#include <iostream>
using namespace std;
int n, m, arr[11];

void solve(int choose){
    if (choose==m){
        for (int i=0; i<m; i++) cout << arr[i] << " ";
        cout << "\n";
        return; // 한 번 루프 끝내고 나가기 
    }
    for (int i=1; i<=n; i++){ // 1부터 n까지 수를 사용 
        int check=0; // 해당 수 사용 여부
        for (int j=0; j<choose; j++) if(arr[j]==i) check=1;
        if (!check){
            arr[choose]=i;
            solve(choose+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    solve(0);
    
}
