#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,P; // N<=400, P<=10000
int flow[401][401];
int cap[401][401];
int pre[401] = {0, };
vector<vector<int>> adj;
int ans;

void maxFlow(int source, int sink){ //1번에서 2번으로 가는 서로 다른 경로의 최대 개수
    memset(flow, 0, sizeof(flow));
    
    while(1){
        queue<int> q;
        memset(pre, -1, sizeof(pre));
        
        q.push(source);
        pre[source] = source;
        
        int min_flow = 987654321;
        
        while(!q.empty()){
            int now = q.front(); q.pop();
            
            //if(now == sink) break;
            
            for(int i=0; i<adj[now].size(); i++){
                int next = adj[now][i];
                
                //방문하지 않은 정점 중 용량이 남는 경우
                if(cap[now][next] - flow[now][next] >0 && pre[next] == -1){
                    q.push(next);
                    pre[next] = now;
                    if(next == sink) break;
                }
            }
        }
        
        //더 이상 증가 경로 없음
        if(pre[sink]==-1) break;
        
        //증가 경로로 새로 흘러줄 유량 = 경로 중 최소 잔여 용량
        for(int i=sink; i!=source; i=pre[i]){
            int j = pre[i];
            min_flow = min(cap[j][i] - flow[j][i], min_flow);
        }
        
        //증가 경로는 유량 증가, 역방향 경로는 유량 감소
        for(int i=sink; i!=source; i=pre[i]){
            int j=pre[i];
            flow[j][i] += min_flow;
            flow[i][j] -= min_flow;
        }
        
        ans += min_flow;
    }
    return;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> P;
    adj.resize(N+1);
    
    for(int i=0; i<P; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] =1;
    }
    
    maxFlow(1,2);
    cout << ans;
    return 0; 
}
