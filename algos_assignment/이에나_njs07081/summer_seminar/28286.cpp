#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 21
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
vector<int> MAP, Correct;
int Answer;

void input() {
    cin >> N >> K;
    Correct.resize(N);
    MAP.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Correct[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> MAP[i];
    }
}

void DFS(int Depth, vector<int> Vec) {
    if (Depth > K) {
        return;
    }

    int Count = 0;
    for (int i = 0; i < N; i++) {
        if (Correct[i] == Vec[i]) {
            Count++;
        }
    }
    Answer = max(Answer, Count);

    for (int i = 0; i < N; i++) {
        if (Vec[i] > 0) {
            vector<int> Tmp;
            Tmp.resize(N);
            Tmp = Vec;
            for (int j = i; j < N; j++) {
                Tmp[j] = Tmp[j + 1];
            }
            Tmp[N - 1] = 0;
            DFS(Depth + 1, Tmp);

            Tmp = Vec;
            for (int j = (N - 1); j > i; j--) {
                Tmp[j] = Tmp[j - 1];
            }
            Tmp[i] = 0;
            DFS(Depth + 1, Tmp);
        }
    }
}

void settings() {
    DFS(0, MAP);
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}
