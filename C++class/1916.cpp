#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int N = 1003;

vector<pair<int,int>> v[N];
int d[N];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0,start));
    
    while (!pq.empty()) {
        int nownode = pq.top().second;
        int nowdist = -pq.top().first;
        pq.pop();

        if (d[nownode] < nowdist) continue;
        
        for (int i = 0; i < v[nownode].size(); i ++) {
            int nextnode = v[nownode][i].second;
            int nextdist = v[nownode][i].first + nowdist;
            
            if(d[nextnode] > nextdist) {
                d[nextnode] = nextdist;
                pq.push(make_pair(-nextdist,nextnode));
            }
        }
    }
}

int main() {
    int nodenum, distnum; cin >> nodenum >> distnum;
    
    for (int i = 0; i < distnum; i ++) {
        int node1, node2, dist; cin >> node1 >> node2 >> dist;
        v[node1].push_back(make_pair(dist,node2));
    }
    
    int start, end; cin >> start >> end;
    
    for (int i = 0; i < N; i ++) {
        d[i] = INF;
    }
    dijkstra(start);
    cout << d[end];
    
}