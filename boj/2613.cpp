#include <iostream>
#include <algorithm>

#define MAX_N 300
#define inf 2147483647

using namespace std;

int beads[MAX_N+1];
int dp[MAX_N+1][MAX_N+1];
int sum[MAX_N+1][MAX_N+1];
int Count[MAX_N+1][MAX_N+1];
int n;
int m;


int solve(int start, int div) {
    int temp;
    int min=inf;


    if(div==1){
        Count[start][div]=n+1-start;
        dp[start][div]=sum[start][n];
        return dp[start][div];
    }

    if(dp[start][div]!=0){
        return dp[start][div];
    }

    dp[start][div]=inf;

    for(int i=start; i<=n-div+1; i++){
        temp= max(sum[start][i], solve(i+1, div-1));
        if(temp<min){
            min=temp;
            Count[start][div]=i-start+1;
        }
    }
    dp[start][div]=min;
    return dp[start][div];
}


int main() {
    int ans;
    int route=1;
    scanf("%d %d",&n,&m);

    for(int i=1; i<=n; i++){
        scanf("%d",&beads[i]);
    }


    for(int j=1; j<=n; j++){
        for(int i=1; i<=j; i++){
            sum[i][j]=sum[i][j-1]+beads[j];
        }
    }

    ans= solve(1,m);

    printf("%d\n", ans);

    for(int i=m; i>0; i--){
        printf("%d ", Count[route][i]);
        route+=Count[route][i];
    }

    return 0;
}