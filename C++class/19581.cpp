#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 100005;
const int INF = 1e9;
vector<pair<int, int>> v[N];
int d[N];
int res1, res2;

void dijkstra(int start) {
    fill(d, d + N, INF);
    d[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));

    while(!q.empty()) {
        int nownode = q.top().second;
        int nowdist = -q.top().first;
        q.pop();

        if(d[nownode] < nowdist) continue;

        for (int i = 0; i < v[nownode].size(); i ++) {
            int nextnode = v[nownode][i].second;
            int nextdist = v[nownode][i].first + nowdist;

            if(d[nextnode] > nextdist) {
                d[nextnode] = nextdist;
                q.push(make_pair(-nextdist,nextnode));
            }
        }
    }
}

int main() {
    int nodenum; cin >> nodenum;
    for (int i = 0; i < nodenum - 1; i ++) {
        int from, to, dist; cin >> from >> to >> dist;
        v[from].push_back(make_pair(dist,to));
        v[to].push_back(make_pair(dist,from));
    }
    dijkstra(1);
    int r1 = 0; // 최장길이
    int check1; // 최장노드
    for (int i = 1; i <= nodenum; i ++) {
        if(r1 < d[i]) {
            check1 = i;
            r1 = d[i];
        }
    }
    dijkstra(check1);
    int r2 = 0;
    int check2;
    for (int i = 1; i <= nodenum; i ++) {
        if(r2 < d[i]) {
            check2 = i;
            r2 = d[i];
        }
    }
    d[check2] = 0;
    r2 = 0;
    for (int i = 1; i <= nodenum; i ++) {
        if(r2 < d[i]) {
            r2 = d[i];
        }
    }
    int res1 = r2;
    dijkstra(check2);
    d[check1] = 0;
    r1 = 0;
    for (int i = 1; i <= nodenum; i ++) {
        if(r1 < d[i]) {
            r1 = d[i];
        }
    }
    int res2 = r1;

    cout << max(res1,res2);
}