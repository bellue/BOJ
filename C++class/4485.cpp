// 다익스트라

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 203;
const int INF = 1e9;

vector<pair<int, int>> v[N];
int d[N];

int main() {
    
    while(1) {
        int n ; cin >> n;
        int cost[n][n];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int k; cin >> k;
                cost[i][j] = k;
            }
        }

        //그래프만 그리면 끝이야!!!!!!!!
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if(i == 0 && j == 0) continue;
                else if(i == 0) {
                    v[i].push_back(make_pair(cost[i][j],j));
                }
                else if(j == 0) {
                    
                }
            }
        }

        int dist[n];
    }
}