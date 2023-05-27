#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1003;
const int INF = 1e8;
vector<pii> adj1[N];
vector<pii> adj2[N];
int n, m, x; 
int dist1[N];
int dist2[N];

void dijkstra(vector<pii> v[], int dist[]) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    fill(dist, dist + N, INF);
    pq.push({0, x});
    dist[x] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (auto [nxt, d] : v[cur]) {
            if (dist[cur] + d < dist[nxt]) {
                dist[nxt] = dist[cur] + d;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
    dijkstra(adj1, dist1);
    dijkstra(adj2, dist2);      
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dist1[i] + dist2[i]);
    printf("%d", ans);
}