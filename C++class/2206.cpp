#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

const int N = 1003;

int Map[N][N];
bool visited[N][N][2]; // 마지막은 벽 부셨는지 여부
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, m;

int bfs(int N, int M) {
    queue<pair<pair<int,int>,pair<int,int>>> q; // x,y좌표 , 벽 부셨는지 여부, 몇번째 칸인지(cnt)
    q.push({{0,0},{0,1}});
    visited[0][0][0] = 1; 
    
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(x == N-1 && y == M-1) return cnt;

        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(Map[nx][ny] == 1 && w == 0) {
                    visited[nx][ny][w+1] = 1;
                    q.push({{nx, ny},{w + 1, cnt + 1}});
                }
                else if(Map[nx][ny] == 0 && visited[nx][ny][w] == 0) {
                    visited[nx][ny][w] = 1;
                    q.push({{nx, ny}, {w, cnt + 1}});
                }
            }
        }
    }
    return -1;
    
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        for (int j = 0; j < m; j ++) {
            char c; 
            c = s[j];
            Map[i][j] = c - '0'; 
        }
    }
    int result = bfs(n, m);

    cout << result;
    
}