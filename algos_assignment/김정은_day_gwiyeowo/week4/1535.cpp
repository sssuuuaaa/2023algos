#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//체력은 100, 기쁨은 0 -> 최대 기쁨을 출력
int n;
vector<int> strength;
vector<int> happy;

int max_pleasure = 0;

void solve(int idx, int strong, int pleasure) {
    
    if(strong <= 0 || idx >= n) {
        if(max_pleasure < pleasure) {
            max_pleasure = pleasure;
        }
        return;
    }
    
    //포함하는 경우, 포함하지 않는 경우
    solve(idx+1,strong-strength[idx], pleasure + happy[idx]);
    solve(idx+1,strong, pleasure);
}

int main() {
    cin >> n;
    
    for(int i =0; i < n; i++) {
        int x;
        cin >> x;
        strength.push_back(x);
    }
    
    for(int i =0; i < n; i++) {
        int x;
        cin >> x;
        happy.push_back(x);
    }
    solve(0,100,0);
    
    cout << max_pleasure << endl;
    
