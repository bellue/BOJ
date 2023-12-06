//https://m.blog.naver.com/ndb796/221234424646 다익스트라(with priority queue)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

const int N = 20004;
const int INF = 1e9;

vector<pair<int, int>> v[N];
int d[N];

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
            int next = v[nownode][i].second;
            int nextdist = v[nownode][i].first + nowdist;
        
            if(d[next] > nextdist) {
                d[next] = nextdist;
                pq.push(make_pair(-nextdist,next));
            }
        }
        
        
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodenum, edgenum, start; cin >> nodenum >> edgenum >> start;
    for (int i = 0; i < edgenum; i ++) {
        int node1, node2, dist; cin >> node1 >> node2 >> dist;
        v[node1].push_back(make_pair(dist,node2));
    }
    for (int i = 0; i <= nodenum; i ++) {
        d[i] = INF;
    }
    
    dijkstra(start);
    
    for (int i = 1; i <= nodenum; i ++) {
        if(d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
    
}
