#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int N = 102;

bool visited[N][N];
char d[N][N];
char und[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n, cnt;

void bfs(char d[][N]) {
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        char color = d[x][y];
        q.pop();

        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            char ncolor = d[nx][ny];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n ) {
                continue;
            } 
            if(ncolor == color) {
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
            
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        for (int j = 0; j < n; j ++) {
            d[i][j] = s[j];
        }
    }
    copy(&d[0][0], &d[0][0] + n * n, &und[0][0]);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if(und[i][j] == 'G') und[i][j] = 'R'; 
        }
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if(!visited[i][j]) {
                cnt1 ++;
                bfs(d);
            }
        }
    }
    fill(&visited[0][0], &visited[n-1][n-1], 0);
        for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if(!visited[i][j]) {
                cnt2 ++;
                bfs(und);
            }
        }
    }
    cout << cnt1 << endl << cnt2;
}