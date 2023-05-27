#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int INF = 1e9+7;
const int M = 52;
int c[M][M], f[M][M];
vector<int> llist[M]; // 인접리스트

inline int ctoi(char c) {
    if(c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main(){
    int cap, N;
    cin >> N;
    for (int i = 0; i < N; i ++) {
        char a, b;
        cin >> a >> b >> cap;

        a = ctoi(a);
        b = ctoi(b);

        c[a][b] = c[b][a] += cap; // capacity 저장
        llist[a].push_back(b);
        llist[b].push_back(a);
    }

    int s = ctoi('A');  int t = ctoi('Z');
    int res = 0;

    while(1) {
        int check[M];
        memset(check, -1, sizeof(check));
        queue<int> v;
        v.push(s);

        while(!v.empty() && check[t] == -1) {
            int cur = v.front();
            v.pop();
            for (int next : llist[cur]) {
                if (c[cur][next] > f[cur][next] && check[next] == -1) {
                    v.push(next);
                    check[next] = cur;
                    if(next == t) break;
                }
            }
        }

        if (check[t] == -1) break;

        int Min = INF;
        for (int i = t; i != s; i = check[i]){
            Min = min(Min, c[check[i]][i] - f[check[i]][i]);
        } // 허용치가 가장 낮은 간선

        for (int i = t; i != s; i = check[i]){
            f[check[i]][i] += Min;
            f[i][check[i]] -= Min;
        }        

        res += Min;
    }

    cout << res;
}