#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M; // 직원 N<=1000, 해야할 일 M<=1000
int K; // 일 2개할 수 있는 직원 K<=1000
vector<int> v[1001];
int work[1001];
bool visited[1001];
int ans=0;

bool dfs(int x){
    for (int i = 0; i < v[x].size(); ++i) {
            int t = v[x][i];
     
            if (visited[t]) continue;
        
            visited[t] = true;
     
            if (work[t] == 0 || dfs(work[t])) {
                work[t] = x;
                return true;
            }
        }
        return false;}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;
    for(int i=1; i<=N; ++i){
        int c; cin >> c;
        for(int j=0; j<c; ++j){
            int num; cin >> num;
            v[i].push_back(num);
        }
    }
    
    fill(work, work+1001, 0);
    
    for(int i=1; i<=N; ++i){
        fill(visited, visited+1001, false);
        if(dfs(i)) ++ans;
    }
    
    for (int i=1; i<=N; ++i) {
        fill(visited, visited + 1001, false);
        if (dfs(i)) {
            ++ans;
            --K;
            if (K == 0) break;
        }
    }
     
    cout << ans << "\n";
    return 0;
}
