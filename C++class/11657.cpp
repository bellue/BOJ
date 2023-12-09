// https://velog.io/@jxlhe46/%EC%B5%9C%EB%8B%A8-%EA%B2%BD%EB%A1%9C-%EB%B2%A8%EB%A7%8C-%ED%8F%AC%EB%93%9C-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 503;
const int INF = 1e9;
long long d[N];
vector<pair<int, pair<int, int>>> v;

bool bellman_ford(int start, int n) {
    d[start] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < v.size(); j ++) {
            int from = v[j].first;
            int to = v[j].second.first;
            int cost = v[j].second.second;

            if(d[from] == INF) continue;

            if(d[to] > d[from] + cost) {
                d[to] = d[from] + cost;

                if(i == n) return true;
            }
        }
    }
    return false;
}

int main() {
    int nodenum, edgenum; cin >> nodenum >> edgenum;

    for (int i = 0; i < edgenum; i ++) {
        int from, to, cost; cin >> from >> to >> cost;
        v.push_back({from, {to, cost}});
    }

    fill(d, d + N, INF);

    int cycle = bellman_ford(1,nodenum);

    if(cycle) {
        cout << "-1";
        return 0;
    }
    else {
        for (int i = 2; i <= nodenum; i ++) {
            if(d[i] == INF) cout << "-1" << '\n';
            else cout << d[i] << '\n';
        }
    }
}