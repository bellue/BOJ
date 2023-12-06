#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1003;
const int INF = 1e9;
int enode1, enode2;

int d[N];
vector<pair<int, int>> v[N];

bool check[N];


void dijkstra(int start) {
    priority_queue<pair<int,int>> pq;
    d[start] = 0;
    pq.push(make_pair(0,start));
    
    while(!pq.empty()) {
        int nownode = pq.top().second;
        int nowdist = -pq.top().first;
        pq.pop();
        
        if(d[nownode] < nowdist) continue;
        
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
    int nodenum, edgenum; cin >> nodenum >> edgenum;
    for (int i = 0; i < edgenum; i ++) {
        int node1, node2, dist; cin >> node1 >> node2 >> dist;
        v[node1].push_back(make_pair(dist,node2));
    }
    
    cin >> enode1 >> enode2;
    
    for(int i = 0; i <=nodenum; i ++) d[i] = INF;
    dijkstra(1);
    
    
    
    
}
