#include <iostream>
#include <string>
#include <cmath>
#define PERSEC 100000000
using namespace std;

int fact(int n){
    int result = 1;
    for(int i=1; i<=n; i++) result = result*i;
    return result;
}

int main() {
    int time;
    long long max_input, n_case, test_case;
    string timeCplx;
    
    cin >> n_case;
    for (int k=0; k<n_case; k++){
        cin >> timeCplx >> max_input >> test_case >> time;
       
        if(timeCplx == "O(N)") {
            if (max_input * test_case <= time * PERSEC) cout << "May Pass." << "\n";
            else cout << "TLE!\n";
        }
        else if (timeCplx == "O(2^N)"){
            if (pow(2,max_input) * test_case <= time * PERSEC) cout << "May Pass." << "\n";
            else cout << "TLE!" << "\n";
        }
        else if (timeCplx == "O(N^2)"){
            if (max_input * max_input * test_case <= time * PERSEC) cout << "May Pass." << "\n";
            else cout << "TLE!" << "\n";
        }
        else if (timeCplx == "O(N^3)"){
            if (max_input * max_input * max_input * test_case <= time * PERSEC) cout << "May Pass." << "\n";
            else cout << "TLE!" << "\n";
        }
        else if (timeCplx == "O(N!)"){
            //
            if (fact(max_input) * test_case <= time * PERSEC) cout << "May Pass." << "\n";
            else cout << "TLE!" <<"\n";
        }
    }
    return 0;
}
