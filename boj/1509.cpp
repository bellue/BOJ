#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 100000000

using namespace std;

bool dp[2503][2503];

int main() {
string s; cin >> s;
//fill(dp,dp+2503,false);
memset(dp, 0, sizeof(dp));
int sl = s.size();
string d = " " + s;

    for (int i = 1; i <= sl; i ++) {
        for (int j = 1; j <= sl; j ++) {
            if(i == j) dp[i][j] = 1;
        }
    }

    for (int i = 0; i < sl; i ++) {
        for (int j = 1; j+i <= sl; j ++) {
            if(j+i <= sl)
            if (d[j] == d[j+i] && (dp[j+1][j+i-1] || i == 1)) {
                dp[j][j+i] = 1;                    
            }
        }
    }
    

    int res[sl + 1] = {0,}; 

    res[0] = 0;
    //cout << dp[0][3] << endl;

    for(int i = 1; i <= sl; i ++) {
        res[i] = inf;
        for (int j = 1; j <= i; j ++) {
            if(dp[j][i] && res[i] > res[j-1] + 1) {
                res[i] = res[j-1] + 1;
            }
        }
    }

    cout << res[sl];
}