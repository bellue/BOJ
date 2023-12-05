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

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodenum, edgenum, start; cin >> nodenum >> edgenum >> start;
    for (int i = 0; i < edgenum; i ++) {
        int node1, node2, dist; cin >> node1 >> node2 >> dist;
        v[node1].push_back(make_pair(node2, dist));
    }
    


}