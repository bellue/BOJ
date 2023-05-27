#include <bits/stdc++.h>
#define INF 1e8

using namespace std;

const int N = 302;

int dp[N][N]; // 최댓값의 최솟값 저장
int sum[N][N];
int mu[N];
int c[N][N];


int d(int now, int cnt, int n) {
    if (cnt == 1) {
        c[now][cnt] = n + 1 - now;
        dp[now][cnt] = sum[now][n];
        return dp[now][cnt];
    }

    if (dp[now][cnt] != 0) {
        return dp[now][cnt];
    }

    int min = INF;
    dp[now][cnt] = INF;
    int m = 0;
    for (int i = now; i <= n - cnt + 1; i ++) {
        m = max(sum[now][i], d(i + 1, cnt - 1, n));
        if (m < min) {
            min = m;
            c[now][cnt] = i - now + 1;
        }
    }

    return dp[now][cnt] = min;

}

int main() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        mu[i] = x;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            sum[j][i] += sum[j][i-1] + mu[i]; // j부터 i까지의 합 
        }
    }

    cout << d(1,m,n) << "\n";

    int k = 1;
    for (int j = m; j > 0; j --) {
        cout << c[k][j] << " ";
        k += c[k][j];
    }
    
}