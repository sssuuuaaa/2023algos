// bfs 메소드
#include <iostream>
#include <queue>
#include <cstring> 
 
using namespace std;
 
#define MAX 50
 
int dir[4][2] = {
    { 0, -1 },{ -1, 0 },{ 0, 1 },{ 1, 0 } // 서 북 동 남
 
};
int map[MAX][MAX];
bool visited[MAX][MAX];
 
int n, m, roomCnt = 0, maxArea = -123123;
 
bool boundary(int row, int col) {
    return (row >= 0 && row < m) && (col >= 0 && col < n);
}
 
void bfs(int row, int col) {
 
    if (visited[row][col])
        return;
 
    int cnt = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    visited[row][col] = true;
 
    while (!q.empty()) {
 
        pair<int, int> p = q.front();
        q.pop();
        int cX = p.first;
        int cY = p.second;
        cnt++;
 
        for (int i = 0; i < 4; i++) {
 
            if ( ((1 << i) & map[cX][cY]) == 0) {
 
                int nX = cX + dir[i][0];
                int nY = cY + dir[i][1];
 
                if (!visited[nX][nY] && boundary(nX, nY)) {
                    visited[nX][nY] = true;
                    q.push(make_pair(nX, nY));
 
                }
            }
 
        }
    }
    roomCnt++;
    if (maxArea < cnt)
        maxArea = cnt;
}
 
void tearDown(int row, int col) {
 
    for (int i = 0; i < 4; i++) {
 
        if ((map[row][col] & (1 << i)) != 0) {
 
            memset(visited, false, sizeof(visited));
            map[row][col] = map[row][col] - (1 << i);
            bfs(row, col);
            map[row][col] = map[row][col] + (1 << i);
 
        }
 
    }
}
 
int main(void) {
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bfs(i, j);
        }
    }
 
 
    cout << roomCnt << endl;
    cout << maxArea << endl;
 
    maxArea = -123123;
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tearDown(i, j);
        }
    }
 
    cout << maxArea << endl;
 
 
    return 0;
}


// https://ghkvud2.tistory.com/11
