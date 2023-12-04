//https://blog.myungwoo.kr/112 트리의 지름 구하기

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int N = 100005;
int visited[N];
vector<pair<int,int>> tree[N];
int maxnode, maxdist;


void dfs(int i, int dist) { //maxdist랑 maxnode구하는게 목표
    if (visited[i]) return;

    if (maxdist < dist) {
        maxdist = dist;
        maxnode = i;
    }

    visited[i] = 1;

    for (int j = 0; j < tree[i].size(); j ++) {
        int nownode = tree[i][j].first;
        int nowdist = tree[i][j].second;
        dfs(nownode, nowdist + dist);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        int a, num, dis;
        cin >> a;
        while(1) {
            cin >> num;
            if(num == -1) break;
            else {
                cin >> dis;
                tree[a].push_back(make_pair(num,dis)); // 노드 a와 num 사이의 거리가 dis 
            }
        }
    }

    dfs(1, 0);
    fill(visited,visited + N, 0);
    dfs(maxnode, 0);

    cout << maxdist;
}