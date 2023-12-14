// bfs 연구소

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int N = 8;
int n,m; 
int d[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;
int tmp[N][N];
bool visited[N][N];

void bfs() { // 바이러스 퍼졌을 때 ans값 구하기
    int arr[N][N];
    copy(&tmp[0][0], &tmp[0][0] + N * N, &arr[0][0]);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if(arr[i][j] == 2) {
                q.push(make_pair(i,j));
            }
        }
    }
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if(arr[nx][ny] == 0) {
                    arr[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
                
        }
    }
        int count = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if(arr[i][j] == 0) {
                    count ++;
                }
            }
        }
    ans = max(ans, count);
    
    


}

void wall(int cnt) { // nC3 , 전형적인 재귀함수 구조
    if(cnt == 3) {
        bfs();
        return;
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if(tmp[i][j] == 0) {
                tmp[i][j] = 1;
                wall(cnt + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int x; cin >> x;
            d[i][j] = x;
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if(d[i][j] == 0) {
                memset(visited, 0, sizeof(visited));
                copy(&d[0][0], &d[0][0] + N * N, &tmp[0][0]);
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }

    cout << ans;

}