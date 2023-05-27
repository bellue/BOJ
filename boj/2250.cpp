#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+4;
const int imf = 1e5+5;
bool visited[N];
vector<pair<int,int>> tree[N];
int node[N]; // 내 위로 노드 몇개있는지 확인
int myparent[N];
int rcnum[N][2];  // 행,열 번호 저장
int cur = 1;
int root;
int col = 1;
int becol;
bool flag;



void inorder(int node, int h){
    if(node == -1){
        return ;
    }

    inorder(tree[node][0].first, rcnum[node][0]);
    rcnum[node][1] = col;
    col ++;
    inorder(tree[node][0].second, rcnum[node][0]);
}

int main(){
    int n; scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) {
        int p,l,r;
        scanf("%d %d %d", &p, &l, &r);
        tree[p].push_back(make_pair(l,r));
        myparent[l] = p;
        myparent[r] = p;
    }
    
    for (int i = 1; i <= n; i ++) {
        rcnum[i][0] = 1;
    }

    for (int i = 1; i <= n; i ++) {
        int k = i;
        while(myparent[k]){
            k=myparent[k];
            rcnum[i][0] ++; // 행번호 get
        }
    }

    for (int i = 1; i <= n; i ++) {
        if(!myparent[i]) root = i;
    } // 루트 get

    
    inorder(root,rcnum[root][0]);

    int maxw = 0;
    int maxh = 1;
    vector<pair<int,int>> v;
    
    for (int i = 1; i <= n; i ++ ) {
        v.push_back(make_pair(rcnum[i][0],rcnum[i][1]));
    }
    sort(v.begin(),v.end());
    

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if(v[i].first == v[j].first) {
                if(maxw < abs(v[i].second - v[j].second)) {
                    maxw = abs(v[i].second - v[j].second);
                    maxh = v[i].first;
                }
            }
        }
    }
    cout << maxh << " " << maxw+1;

}
