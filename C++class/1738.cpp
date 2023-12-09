#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 102;
const int INF = 1e9;

vector<pair<int, pair<int, int>>> v;
int d[N];
int nodenum, edgenum;

int bellman_ford(int start) {
    d[start] = 0;

    for (int i = 1; i <= nodenum; i ++) {
        for (int j = 0; j < v.size(); j ++) {
            int from = v[j].first;
            int to = v[j].second.first;
            int cost = v[j].second.second;

            if(d[from] == INF) continue;

            
        }
    }
}

int main() {
    cin >> nodenum >> edgenum;

    for (int i = 0; i < edgenum; i ++) {
        int from, to, cost; cin >> from >> to >> cost;
        v.push_back({from,{to,-cost}});
    }

    fill(d,d+N,INF);

}