#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 200002
#define INF 987654321

int parent[MAX];
int height[MAX]={0,};

int Find(int u){
    if (parent[u]==u)
        return u;
    return Find(parent[u]);
}

void Union(int u,int v){
    u=Find(u);
    v=Find(v);
    if (u==v)
        return;
    
    if (height[u]<height[v])
        swap(u,v);
    parent[v]=u;
    
    if (height[u]==height[v])
        height[u]++;
    return;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    int a;
    int arr[MAX];
    vector <pair<int,int>> v;
    vector <int> result;
        
    cin>>n>>q;
    for (int i=0;i<=n;i++)
        parent[i]=i;
        
    arr[1]=1;
    for (int i=1;i<n;i++){
        cin>>a;
        arr[i+1]=a;
    }
        
    int k=n-1+q;
    while (k--){
        int x;
        cin>>x;
            
        if (x==0){
            int b;
            cin>>b;
            v.push_back({0,b});
        }
            
        else if (x==1){
            int c,d;
            cin>>c>>d;
            v.push_back({c,d});
        }
    }
        
    k=n-1+q;
    for (int i=k-1;i>=0;i--){
        if (!v[i].first){
            Union(arr[v[i].second],v[i].second);
        }
            
        else{
            if (Find(v[i].first)==Find(v[i].second))
                result.push_back(1);
            else
                result.push_back(0);
        }
    }
        
    for (int i=q-1;i>=0;i--){
        if (result[i]==1)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}
