
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int arr[100001];
string str;

vector<int> input() {
    vector<int> nums;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }
    return nums;
}


int main() {
    cin >> N;
    
    vector<int> a = input();
    
    int ans = 0;
    for (int i : a) {
        ans ^= i - 2;
    }

    cin >> str;
        
    if (str == "Whiteking") {
        cout << (ans ? "Whiteking" : "Blackking") << "\n";
    } else {
        cout << (ans ? "Blackking" : "Whiteking") << "\n";
    }
    
    return 0;
}

