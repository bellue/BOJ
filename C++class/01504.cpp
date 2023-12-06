#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1003;
const int INF = 1e9;

int d[N];
vector<pair<int, int>> v[N];


void dijkstra(int start) {
    priority_queue<pair<int,int>> pq;
    int nownode = start;
    int nowdist = 0;
    pq.push_back(make_pair(nowdist,nownode));
    
    while(!pq.empty()) {
    }
    
}

int main() {
    int nodenum, edgenum; cin >> nodenum >> edgenum;
    for (int i = 0; i < edgenum; i ++) {
        int node1, node2, dist; cin >> node1 >> node2 >> dist;
        v[node1].push_back(make_pair(dist,node2));
    }
    
    int enode1, enode2; cin >> enode1 >> enode2;
    
    dijkstra(1);
    
    
}
