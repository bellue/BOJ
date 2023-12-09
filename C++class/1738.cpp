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
int pre[N];
bool visited[N];

int bellman_ford(int start) {
    d[start] = 0;

    for (int i = 1; i <= nodenum; i ++) {
        for (int j = 0; j < v.size(); j ++) {
            int from = v[j].first;
            int to = v[j].second.first;
            int cost = v[j].second.second;

            if(d[from] == INF) continue;

            if(d[to] > d[from] + cost) {
                d[to] = d[from] + cost;

                if(i == nodenum) return true;
            }
            
        }
    }
    return false;
}

int main() {
    cin >> nodenum >> edgenum;
    vector<int> way[N];
    for (int i = 0; i < edgenum; i ++) {
        int from, to, cost; cin >> from >> to >> cost;
        v.push_back({from,{to,-cost}});
        way[to].push_back(from);
    
    }

    fill(d,d+N,INF);
    int cycle = bellman_ford(1);
    
    queue<int> q;
    q.push(nodenum);
    //여기부터
    while(q.empty()) {
        int a = q.front();
        q.pop();
        visited[a] = 1;
        for (int i = 0; i < way[a].size(); i ++) {
            q.push(way[a][i]);
            visited[way[a][i]];
        }

    }
    
    if(cycle) {
        cout << "-1";
        return 0;
    }



}