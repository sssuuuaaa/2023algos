#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define MAX 10002
#define INF 987654321

vector <pii> v;
stack <pii> s;
int n;

ll ccw(pii a, pii b, pii c){
    return a.first*b.second + b.first*c.second + c.first*a.second - (b.first*a.second + c.first*b.second + a.first*c.second);
}

bool compare(pii a, pii b){
    ll tmp = ccw(v[0], a, b);
    
    if (tmp)
        return tmp>0;
    
    else if (a.second != b.second)
        return a.second < b.second;
    
    else
        return a.first < b.first;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    v.resize(n);
    
    for (int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    
    for (int i=1; i<n; i++){ //1부터
        if(v[i].second < v[0].second || (v[i].second == v[0].second && v[i].first < v[0].first)){
            swap(v[0].first, v[i].first);
            swap(v[0].second, v[i].second);
        }
    }
    
    sort(v.begin()+1, v.end(), compare);
    s.push(v[0]); s.push(v[1]);
    
    for (int i=2; i<n; i++){
        while(s.size() >= 2){
            pii t2 = s.top();
            s.pop();
            
            pii t1 = s.top();
            if (ccw(t1, t2, v[i]) > 0){
                s.push(t2);
                break;
            }
        }
        s.push(v[i]);
    }
    
    cout<<s.size();
}
