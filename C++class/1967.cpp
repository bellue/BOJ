#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int N = 10004;
int visited[N];
vector<pair<int,int>> tree[N];
int maxnode, maxdist;

void dfs(int i, int dist) {
    if (visited[i]) return;

    if (maxdist < dist) {
        maxdist = dist;
        maxnode = i;
    }

    visited[i] = 1;

    for (int j = 0; j < tree[i].size(); j ++) {
        int nownode = tree[i][j].first;
        int nowdist = tree[i][j].second;
        dfs(nownode, nowdist + dist);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n - 1; i ++) {
        int a; cin >> a;
        int b,dis; cin >> b >> dis;
        tree[a].push_back(make_pair(b,dis));
        tree[b].push_back(make_pair(a,dis));
    }

    dfs(1, 0);
    fill(visited, visited + N, 0);
    dfs(maxnode, 0);

    cout << maxdist;
}