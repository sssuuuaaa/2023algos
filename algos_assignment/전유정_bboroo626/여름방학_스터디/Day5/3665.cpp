#include<iostream>
#include<algorithm>
 
using namespace std;
 
//작년 순위
int LastRank[501];
//자신의 앞에 있는 사람의 수
int Count[501];
//올해 순위를 정할때 활용.
pair<int, int> Rank[501];
 
int main() {
    int T, N, M;
    int a, b;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            //순서대로 입력을 받아서
            cin >> a;
            //이번 순서에 앞에 있는 사람의 수는 i
            Count[a] = i;
            //그리고 이번 순서를 기록(i+1)
            LastRank[a] = i + 1;
        }
 
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            //내 순위가 더 높았다면, count를 그대로 반영
            if (LastRank[a] > LastRank[b]) {
                Count[a]--;
                Count[b]++;
            }
            else {
                Count[a]++;
                Count[b]--;
            }
        }
 
        // 이름 저장해주기 위해서 pair로 구현
        for (int i = 0; i < N; i++) {
            Rank[i] = { Count[i+1], i + 1 };
        }
 
        //first를 기준으로 오름차순 정렬
        sort(Rank, Rank + N);
 
        //이번 배열중에 순위를 확정지을 수 있는지 확인
        bool isPossible = true;
        for (int i = 0; i < N; i++) {
            //만일 이번 순서의 Count가 i와 같지 않다면,
            if (Rank[i].first != i) {
                //불가능한 배열이고 반복을 종료
                isPossible = false;
                break;
            }
        }
 
        if (!isPossible) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        //가능한 배열이라면 순서대로 이름을 출력
        for (int i = 0; i < N; i++) {
            cout << Rank[i].second << " ";
        }
        cout << endl;
    }
 
 
    return 0;
}


// https://kyunstudio.tistory.com/126
