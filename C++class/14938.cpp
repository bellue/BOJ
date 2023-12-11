// 다익스트라

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 103;
const int INF = 1e9;

vector<pair<int, int>> v[N];
int n, m, r;
int d[N];
int item[N];

void dijkstra(int start) {
    for (int j = 0; j < N; j ++) d[j] = INF;
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
                pq.push(make_pair(-nextdist, nextnode));
            }
        }

    }


}

int main() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i ++) {
        cin >> item[i];
    }

    for (int i = 0; i < r; i ++) {
        int from, to, cost; cin >> from >> to >> cost;
        v[from].push_back(make_pair(cost,to));
        v[to].push_back(make_pair(cost,from));
    }
    // pq이용 다익스트라로 d 채우고 거리 내에서 item개수 합산의 최댓값 구하자.
    int res[N]; fill(res, res + N, 0);
    for (int i = 1; i <= n; i ++) {
        dijkstra(i);
        for (int j = 1; j <= n; j ++) {
            if(d[j] <= m) res[i] += item[j];
        }
    }
    int Max = 0;
    for(int i = 1; i <= n; i ++) {
        Max = max(res[i], Max);
    }
    cout << Max;
}