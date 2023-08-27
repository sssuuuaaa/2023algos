#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 100005
#define INF 987654321

int N, x, y;
int M, u, v;
int H;


vector <int> arr[MAX];
int stable[MAX][20];
int depth[MAX];

void dfs(int node, int parent){
    depth[node] = depth[parent] + 1;
    
    for (int i=0; i<arr[node].size(); i++){
        int nextnode = arr[node][i];
        
        if (nextnode != parent){
            stable[nextnode][0] = node;
            dfs(nextnode, node);
        }
    }
    return;
}

void init(){
    for (int i=1; i<=H; i++){
        for (int j=1; j<=N; j++){
            stable[j][i] = stable[stable[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v){
    if (depth[u] > depth[v])
        swap(u, v);
    
    for (int i=H; i>=0; i--){
        if (depth[v] - depth[u] >= (1<<i)){
            v = stable[v][i];
        }
    }
    
    if (u == v)
        return u;
    
    for (int i=H; i>=0; i--){
        if (stable[u][i] != stable[v][i]){
            u = stable[u][i];
            v = stable[v][i];
        }
    }
    return stable[u][0];
}


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>N;
    for (int i=0; i<N-1; i++){
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    H = ceil(log2(N))+1;
    
    dfs(1, 0);
    init();
    
    cin>>M;
    for (int i=0; i<M; i++){
        cin>>u>>v;
        cout<<lca(u, v)<<"\n";
    }
}
