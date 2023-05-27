#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int numNodes, numEdges, maxCost, startNode, endNode;
const int MAX = 100005;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

void input() {
    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(to, cost);
        graph[to].emplace_back(from, cost);

        maxCost = getMax(maxCost, cost);
    }

    cin >> startNode >> endNode;
}

bool bfs(int curCost) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        if (curNode == endNode)
            return true;

        for (auto& p : graph[curNode]) {
            int nextNode = p.first;
            int nextNodeCost = p.second;

            if (!visited[nextNode] && curCost <= nextNodeCost) {
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    return false;
}

void solution() {
    int low = 0;
    int high = maxCost;
    while (low <= high) {
        memset(visited, false, sizeof(visited));
        int mid = (low + high) / 2;
        if (bfs(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << high << endl;
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
