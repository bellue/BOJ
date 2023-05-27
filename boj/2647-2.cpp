#include<bits/stdc++.h>

using namespace std;

const int N = 103;
int arr[N];
int num[N][N];
int dp[N][N];
int h[N][N];
int C[N][N];

const int inf = 10000007;


int dfs(int s,int e){
    int ans = inf;

    if(s >= e) {
        return 0;
    }

    if(s == e - 1) {
        dp[s][e] = 3;
        C[s][e]=e;
        h[s][e]=1;

        return dp[s][e];
    }

    if(dp[s][e]) {
        return dp[s][e];
    }

    int resh,cal;
    int resnum=-1;

    for (int i = s+1; i <= e; i += 2){
        if(arr[i] != arr[s] && num[s+1][i-1]){
            cal = dfs(s+1,i-1) + (h[s+1][i-1]+1)*2+(i-s) + dfs(i+1,e);
            if(cal < ans) {
                ans = cal;
                resh = max(h[s+1][i-1]+1,h[i+1][e]);
                resnum = i;
            }
        }
    }
    
    dp[s][e] = ans;

    C[s][e]=resnum;
    h[s][e]=resh;

    return dp[s][e];
}

void traceback(int s,int e){
    int k = C[s][e];

    if(s > e) {
        if(k == 0)
            return ;
    }
    
    cout << s << " " << k << '\n';

    traceback(s+1,k-1);
    traceback(k+1,e);
}

int main(){
    int n; cin >> n;

    for (int i = 1; i <= n; i ++) {
        scanf("%1d", &arr[i]);
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n+1; j ++) {
            num[i][j] = num[i][j-1] + arr[j];
        }
    }

    for (int i = 1; i <= n-1; i ++) {
        for (int j = i; j <= n; j ++) { 
            if(num[i][j]*2 == (j-i+1)) {
                num[i][j] = 1;
            }
            else num[i][j] = 0;
        }
    }

    for (int i = 1; i <= n+1; i ++) {
        num[i][i-1]=1;
    }

    cout << dfs(1,n) << "\n";
    
    traceback(1,n);
}