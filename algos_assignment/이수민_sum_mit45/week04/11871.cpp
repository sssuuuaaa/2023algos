#include <iostream>
#include <vector>
using namespace std;

int N;
long long grundy = 0;

int main(){
    cin >> N;
    while(N--){
        long long P;
        cin >> P;
        if(P%2==0){
            grundy ^= P/2-1;
        }
        else{
            grundy ^= P/2+1;
        }
    }
    
    if(grundy!=0){
        cout << "koosaga";
    }
    else{
        cout << "cubelover";
    }
    
    return 0;
}
