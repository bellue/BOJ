#include<iostream>
const int INF = 1e9;
using namespace std;

int color[110],black[110][110];
int con[110][110],H[110][110];
int C[110][110];
int n;

int solve(int s, int e) {
    if(s>=e) return 0;
    if(con[s][e]) return con[s][e];
    if(s+1 == e){
        C[s][e] = e;
        H[s][e] = 1;
        return con[s][e] = 3;
    }
    int ans = INF, height, ans_id = -1, cal;
    for(int t=s+1; t<=e; t+=2){
        if(color[t] != color[s] && black[s+1][t-1]) {
            cal = solve(s+1, t-1) + 2*(H[s+1][t-1]+1) + (t-s) + solve(t+1, e);
            if(cal < ans){
                ans = cal;
                height = max(H[s+1][t-1]+1, H[t+1][e]);
                ans_id = t;
            }
        }
    }
    C[s][e] = ans_id;
    H[s][e] = height;
    return con[s][e] = ans;
}

void find(int s, int e){
    if(s > e || !C[s][e]) return;
    cout << s << " " << C[s][e] << "\n";
    find(s+1, C[s][e]-1);
    find(C[s][e]+1, e);
}

int main(){
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)
        scanf("%1d",color+i);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n+1;j++)
            black[i][j]=black[i][j-1]+color[j];
    for(int i=1;i<n;i++)
        for(int j=i;j<=n;j++)
            black[i][j]=(black[i][j]*2 == (j-i+1));
    for(int i=1;i<=n+1;i++)
        black[i][i-1]=1;
    int ans = solve(1, n);
    printf("%d\n", ans);
    find(1, n);
    return 0;
}