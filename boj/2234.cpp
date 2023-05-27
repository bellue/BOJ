// boj 2234, 성곽
// dfs, 비트마스킹 이용

#include <iostream>
#include <vector>

using namespace std;

const int N = 53;

int Map[N][N];
int visited[N][N];
int roomSize[N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int n, int m) { // 방문한 위치는 1로 변경 후 비트마스킹을 통해 벽의 유무를 확인하며 주변 탐색
    visited[n][m] = 1;
    int size = 1;
    for (int i = 0; i < 4; i ++) {
        if(!(Map[n][m] & (1 << i))) { //Map[n][m]의 i번째 비트수가 1인지 확인
            size ++;
            dfs(n + dx[i], m + dy[i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int maxRoom = 0;
    int n, m ;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> Map[i][j]; // 벽 정보 저장
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if(!visited[n][m]) {
                int roomsize;
            }
        }
    }
    
    
    cout << Map[0][0];
}
