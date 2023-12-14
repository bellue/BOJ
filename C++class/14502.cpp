//https://salon.tistory.com/73

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 8;
int n,m; 
int d[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;
int tmp[N][N];
bool visited[N][N];

void bfs(int start) {

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
                
            }
        }
    }

}