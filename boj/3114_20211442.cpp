#include <bits/stdc++.h>

using namespace std;

const int N = 2003;
int a[N][N];
int b[N][N];
int as[N][N];
int bs[N][N];
int s[N][N];
int dp[N][N];

int main() {
    int r,c; cin >> r >> c;

    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= c; j ++) {
            string s1,s2;
            cin >> s1;
            for(int i = 1; i <= s1.length(); i ++) {
                s2[i-1] = s1[i];
            }
            if(s1[0] =='A') {
                a[i][j] = stoi(s2);
                b[i][j] = 0;
            }
            else {
                a[i][j] = 0;
                b[i][j] = stoi(s2);
            }
        }
    }

    for (int i = c; i >= 1; i --) {
        for (int j = r; j >= 1; j --) {
            as[j][i] = a[j+1][i] + as[j+1][i];            
        }
    }

    for (int i = 1; i <= c; i ++) {
        for (int j = 1; j <= r; j ++) {
            bs[j][i] = b[j-1][i] + bs[j-1][i];
        }
    }
    
    for (int i = 1; i <= r; i ++) {
            bs[i][1] = 0;
    }
    
    
    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= c; j ++) {
            s[i][j] = as[i][j] + bs[i][j];
        }
    }

    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= c; j ++) {
            dp[i][j] = max({dp[i-1][j-1] + s[i][j], dp[i][j-1] + s[i][j], dp[i-1][j] - a[i][j]});
        }
    }

    // for (int i = 1; i <= r; i ++) {
    //     cout << endl;
    //     for (int j = 1; j <=c; j ++) {
    //         cout << b[i][j] << " ";
    //     }
    // }

    cout << dp[r][c];
}