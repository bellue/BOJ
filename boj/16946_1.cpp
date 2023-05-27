#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int n, m, numSets = 1, setSizes[MAX * MAX];
int map[MAX][MAX], setMap[MAX][MAX], result[MAX][MAX];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    setMap[r][c] = numSets;

    int cnt = 0;
    while (!q.empty()) {
        pair<int, int> now = q.front(); 
        q.pop();
        cnt++;
        for (int k = 0; k < 4; k++) {
            int nr = now.first + dr[k], nc = now.second + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (map[nr][nc] > 0 || setMap[nr][nc]) continue;
            setMap[nr][nc] = numSets;
            q.push({nr, nc});
        }
    }
    setSizes[numSets++] = cnt;
}

void solve() {
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            if (map[r][c] == 0 && setMap[r][c] == 0) bfs(r, c);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (map[r][c] > 0) {
                int cnt = 1;
                vector<int> check;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    auto it = find(check.begin(), check.end(), setMap[nr][nc]);
                    if (it != check.end()) continue;
                    check.push_back(setMap[nr][nc]);
                    cnt += setSizes[setMap[nr][nc]];
                }
                result[r][c] = cnt;
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++)
            cout << result[r][c] % 10;
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            map[i][j] = str[j] - '0';
    }
    solve();

    return 0;
}

