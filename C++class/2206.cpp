#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

const int N = 1003;

int Map[N][N];
bool visited[N][N];
int n, m;

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

    
}