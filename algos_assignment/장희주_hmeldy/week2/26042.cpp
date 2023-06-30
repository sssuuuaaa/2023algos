#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);  
    queue <int> line;
    queue <int> answer;
    int n, option, cnt, stu;
    int long max, stu_minNum;
    cin >> n;
    cnt=0; max=0;
    
    for(int k=0; k<n; k++){
        cin >> option;
        
        if (option==1){
            cin >> stu;
            line.push(stu);
        }
        else line.pop();
        
        if(max<line.size()) {
            max = line.size();
            stu_minNum = line.back();
        }
        else if (max==line.size()){
            if(line.back() < stu_minNum){
                stu_minNum = line.back();
            }
        }
    }
    cout << max << " " << stu_minNum;
    
    return 0;
}
