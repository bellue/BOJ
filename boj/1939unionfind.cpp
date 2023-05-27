#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int cost, from, to;
};

int numNodes, numEdges;
vector<int> parent;

int find(int x) {
    if (parent[x] == x)
        return x;
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    parent[max(a, b)] = min(a, b);
}

bool isConnected(int a, int b) {
    return find(a) == find(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numNodes >> numEdges;
    parent.resize(numNodes + 1);

    vector<Edge> edges(numEdges);
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
        edges[i].cost = -edges[i].cost;
    }

    int startNode, endNode;
    cin >> startNode >> endNode;

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost > b.cost;
    });

    for (int i = 1; i <= numNodes; i++)
        parent[i] = i;

    for (const auto& edge : edges) {
        int cost = -edge.cost;
        int from = edge.from;
        int to = edge.to;
        unionSets(from, to);

        if (isConnected(startNode, endNode)) {
            cout << cost << endl;
            break;
        }
    }

    return 0;
}
