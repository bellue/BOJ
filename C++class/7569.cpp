#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 102;

int m, n, h;
int d[N][N][N];


int bfs() {

}

int main() {
    cin >> m >> n >> h;

    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; j < m; j ++) {
                int to; cin >> to;
                d[i][j][k] = to;
            }
        }
    }

    

}