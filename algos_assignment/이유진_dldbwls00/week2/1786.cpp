#include<iostream>
#include<string>
#include<vector>
using namespace std;

string parent;
string pattern;
vector<int> makeTable(string pattern) { //실패함수
    vector<int> table(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i < table.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];

        }
        if (pattern[j] == pattern[i]) {
            table[i] = ++j;
        }
    }
    return table; //table(k): k번째 인덱스에서 접두사와 접미사가 일치하는 최대길이
}
void kmp(string parent, string pattern, vector<int>& table) {
    int j = 0;
    int count = 0;
    vector<int> vt;
    for (int i = 0; i < parent.size(); i++) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (parent[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                count++;
                vt.push_back(i - pattern.size() + 2);
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
    cout << count << '\n';
    for (int i = 0; i < vt.size(); i++) {
        cout << vt[i] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    getline(cin, parent);
    getline(cin, pattern);

    vector<int> table = makeTable(pattern);
    kmp(parent, pattern, table);

    return 0;
}
