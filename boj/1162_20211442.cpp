#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF 10000000000

struct Edge {
    int to;
    long long cost;
    int paved;
};

struct Compare {
    bool operator()(const Edge& a, const Edge& b) {
        return a.cost > b.cost;
    }
};

int n, m, k;
vector<vector<Edge>> graph;
vector<vector<long long>> dist;

void Dijkstra() {
    priority_queue<Edge, vector<Edge>, Compare> pq;
    dist.assign(k + 1, vector<long long>(n + 1, INF));
    dist[0][1] = 0;
    pq.push({ 1, dist[0][1], 0 });

    while (!pq.empty()) {
        Edge curEdge = pq.top();
        pq.pop();
        int cur = curEdge.to;
        long long cost = curEdge.cost;
        int paved = curEdge.paved;

        if (dist[paved][cur] < cost)
            continue;

        for (const auto& nextEdge : graph[cur]) {
            int next = nextEdge.to;
            long long nextCost = cost + nextEdge.cost;

            if (dist[paved][next] > nextCost) {
                dist[paved][next] = nextCost;
                pq.push({ next, nextCost, paved });
            }

            if (paved < k) {
                nextCost = cost;
                int nextPaved = paved + 1;
                if (dist[nextPaved][next] > nextCost) {
                    dist[nextPaved][next] = nextCost;
                    pq.push({ next, nextCost, nextPaved });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int start, end;
        long long cost;
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost, 0 });
        graph[end].push_back({ start, cost, 0 });
    }

    Dijkstra();

    long long minCost = INF;
    for (int i = 0; i <= k; i++) {
        if (minCost > dist[i][n])
            minCost = dist[i][n];
    }
    cout << minCost;

    return 0;
}
