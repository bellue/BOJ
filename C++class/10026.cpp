// bfs 적록색약

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int N = 102;
int INF = 1e9;

int n;
char b[N][N];

void bfs() {
    
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        for (int j = 0; j < n; j ++) {
            b[i][j] = s[j];        
        }
    }

}
