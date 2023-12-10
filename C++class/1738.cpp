//https://blog.naver.com/kks227/220796963742 라이 벨만포드

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
                pre[to] = from; // 마지막까지 갱신되므로
                if(i == nodenum && visited[to]) return true;
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
    
    queue<int> q;
    q.push(nodenum);
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        visited[a] = 1;
        for (int i = 0; i < way[a].size(); i ++) {
            if(!visited[way[a][i]]){ // 이 if문 없을 때도 정상작동 하는지 확인해보기 (내가 생각하는 해당 if문의 역할은 여러가지 길 중 하나의 길만 찾아주는것)
                q.push(way[a][i]);
                visited[way[a][i]] = 1;
            }
        }
    }
    
    int cycle = bellman_ford(1);
    if(cycle) {
        cout << "-1";
        return 0;
    }
    vector<int> res;
    int k = nodenum;
    while(k >= 1) {
        res.push_back(k);
        k = pre[k];
    }
    reverse(res.begin(), res.end());
    for(auto &x : res) cout << x << " ";



}