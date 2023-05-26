#include <iostream>
#include <vector>
using namespace std;

int N;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    vector <int> v(N);
    
    for(int i=0; i<N; i++) cin >> v[i];
    
    int res = v[0];
    
    for(int i=1; i<N; i++) res = res ^ v[i];
    
    if(res==0) cout << "cubelover";
    else cout << "koosaga";
    
    return 0;
}
