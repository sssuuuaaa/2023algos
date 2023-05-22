#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX_NODE 52 // 전체 알파벳 개수
#define INF 1e9 // 최대 유량 비교 시 사용
using namespace std;

int capacity[MAX_NODE][MAX_NODE]; // 용량 배열
int flow[MAX_NODE][MAX_NODE]; // 유량 배열

vector<int> arr[MAX_NODE];
int visited[MAX_NODE];

int N;
int mmax;

int maximum_flow(int source, int sink){ // bfs로 source -> sink 최단경로 탐색

    while(1){ // source -> sink 증가경로 없을때까지 반복
        memset(visited, -1, sizeof(visited));
        queue<int> q;
        q.push(source);

        while(!q.empty()){ //source -> sink BFS 탐색
            int cur = q.front();
            q.pop();

            // 현재 노드와 인접한 노드들을 queue 에 삽입
            for (int i=0; i<arr[cur].size(); ++i){
                int next = arr[cur][i];

                if ((capacity[cur][next] - flow[cur][next] > 0) && (visited[next] == -1)){ //잔여용량 남아있고, 방문하지 않았다면

                    q.push(next); //인접노드 삽입
                    visited[next] = cur; //인접 노드가 현재 노드로부터 방문

                    if (next == sink) break; //탐색 종료
                }
            }
            if (visited[sink] != -1) break; //경로 찾으면 탐색 종료
        }

        // BFS 탐색이 끝났음에도 불구하고, sink_node가 방문하지 않음. source -> sink 경로가 없다는 것이므로 탐색 종료
        if (visited[sink] == -1) break;

        // source 에서 sink 로 가는 증가 경로가 있는 경우
        int tmp = INF;
        int res_c;

        // 방문 노드 배열을 역순으로 탐색하며, 최대 유량 확인
        for (int i=sink; i != source; i=visited[i]){
            res_c = capacity[visited[i]][i] - flow[visited[i]][i]; // 잔여 용량 계산
            tmp = min(tmp, res_c); // 최대 유량과 최소 비교 후 변환
        }

        // 최대 유량을 찾았다면, 다시 방문 노드 배열을 역순으로 탐색하며, 유량 증가
        for (int i=sink; i != source; i=visited[i]){
            flow[visited[i]][i] += mmax; // 이전 노드에서 다음 노드로 가는 유량 증가
            flow[i][visited[i]] -= mmax; // 다음 노드에서 이전 노드로 가는 유량 증가 (역간선)
        }

        // 해당 경로에서 발견된 최대 유량을 결과에 추가
        mmax += tmp;
    }
    return mmax;
}

int main(){
    
    cin >> N ; //간선 개수

    for (int i=0; i<N; ++i){
        char start, end;
        int input_capacity;

        cin >> start >> end >> input_capacity;
        
        // 문자 노드를 숫자 노드로 변경
        int start_int = -1;
        int end_int = -1;
        
        if(start <= 'Z'){ //대문자
            start_int = start - 'A';
        }
        else{ //소문자
            start_int = start - 'a' + 26;
        }
        
        if(end <= 'Z'){ //대문자
            end_int = start - 'A';
        }
        else{ //소문자
            end_int = start - 'a' + 26;
        }

        arr[start_int].push_back(end_int);
        arr[end_int].push_back(start_int);
                               
        capacity[start_int][end_int] += input_capacity;
        capacity[end_int][start_int] += input_capacity;
    }

    // A 부터 Z 까지의 최대 유량 탐색
    cout << maximum_flow(0,25) << endl;
    
    return 0;
}
