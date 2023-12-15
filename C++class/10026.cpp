#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int N = 102;

bool visites[N][N];
char d[N][N];
char und[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(char tmp[][N]) {
    queue<pair<int, int>> q;
    q.push({0,0});

    while(!q.empty()) {
        int a;
    }
}


int main() {
    int n; cin >> n;
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

    bfs(d);


}