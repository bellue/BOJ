// https://www.acmicpc.net/board/view/124591  반례

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1003;
const int INF = 1e9;
int enode1, enode2;
long dist1, dist2, nodenum;

int d[N];
vector<pair<int, int>> v[N];

bool check[N];


void dijkstra(int start) {
    for(int i = 0; i <=nodenum; i ++) d[i] = INF;
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
    int edgenum; cin >> nodenum >> edgenum;
    for (int i = 0; i < edgenum; i ++) {
        int node1, node2, dist; cin >> node1 >> node2 >> dist;
        v[node1].push_back(make_pair(dist,node2));
        v[node2].push_back(make_pair(dist,node1));
    }
    
    cin >> enode1 >> enode2;
    
    dijkstra(1);
    int a1_d1 = d[enode1];
    int a1_d2 = d[enode2];
    
    dijkstra(enode1);
    int d1_d2 = d[enode2];
    int d1_n =  d[nodenum];
    
    dijkstra(enode2);
    int d2_n = d[nodenum];
    
    dist1 = a1_d1 + d1_d2 + d2_n;
    dist2 = a1_d2 + d1_d2 + d1_n;
    
    long Min = min((long)INF, dist2);
    Min = min(Min, dist1);
    
    if (Min >= INF) cout << "-1";
    else cout << Min;
    
}
