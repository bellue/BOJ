#include <bits/stdc++.h>

using namespace std;
const int N = 54;

int MOD = 1e6 + 7;
int dp[N][N][N][N];
int arr[N][N];
int Carr[N][2];
bool check[N];

int d (int r, int c, int pre, int cnt) {
    if (r < 1 || c < 1) return 0;
    
    if (r == 1 && c == 1) {
        if (arr[r][c] && arr[r][c] < pre && cnt == 1) return 1;
        if (!arr[r][c] && cnt == 0) {
            return 1;
        }
        else return 0;
    }

    int &ret = dp[r][c][pre][cnt];

    if (ret != -1) return ret;

    ret = 0;

    if (arr[r][c] < pre && arr[r][c] && cnt) {
        ret = (ret + d(r - 1, c, arr[r][c], cnt - 1)) % MOD;
        ret = (ret + d(r, c - 1, arr[r][c], cnt - 1)) % MOD;
    }
    if (!arr[r][c]) {
        ret = (ret + d(r - 1, c, pre, cnt)) % MOD;
        ret = (ret + d(r, c - 1, pre, cnt)) % MOD;
    }
    return ret;
}

int main() {
    int n,m,c; cin >> n >> m >> c;
    
    for (int i = 1; i <= c; i ++) {
        int x,y; cin >> x >> y;
        Carr[i][0] = x; Carr[i][1] = y;
        arr[x][y] = i;
    }
    bool check[c+1]; fill(check,check+c+1,1);

    if(arr[1][1] || arr[n][m]) check[0] = 0;
    

    for (int i = 1; i < c; i ++) {
        if(Carr[i - 1][0] > Carr[i][0] || Carr[i - 1][1] > Carr[i][1]) {
            for (int j = i; j <= c; j ++) {
                check[j] = 0;
            }
            break;
        }
    } // 순서대로 방문할 수 없는 경우 0으로 예외처리


    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= c; i ++) {
        // if(!check[i]) {
        //     cout << "0 ";
        //     continue;
        // } 
        // else 
        cout << d(n, m, N, i) << " ";
        
    }
}