#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

vector <int> getPi(string p){
    int m = (int)p.size();
    int j=0;
    vector<int> pi(m,0);
    
    for(int i=1; i<m; i++){
        while(j>0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string s, string p){
    vector<int> ans;
    vector<int> pi=getPi(p);
    
    int n=(int)s.size(), m=(int)p.size(), j=0;
    
    for(int i=0; i<n; i++){
        while(j>0 && s[i]!=p[j])
            j=pi[j-1];
        if(s[i] == p[j]){
            if(j==m-1){
                ans.push_back(i-m+1);
                j=pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while(1){
        string s; cin >> s;
        if(s == ".") break;
        
        vector<int> pi= getPi(s);
        
        if(pi[s.size()-1] % (s.size() - pi[s.size()-1])) cout << 1 << '\n';
        else cout <<s.size()/(s.size()-pi[s.size()-1]) << '\n';
    }
    
    
    return 0;
}
