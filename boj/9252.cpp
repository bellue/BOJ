#include <bits/stdc++.h>

using namespace std;

char b[1005][1005];
int dp[1005][1005];
string s1,s2;
vector<char> v;
vector<int> s;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;
    int al = a.length();
    int bl = b.length();
    

    string s1 = '0' + a;
    string s2 = '0' + b;

    for (int i = 1; i <= al; i ++) {
        for (int j = 1; j <= bl; j ++) {
            if (!s1[i] || !s2[j]) {
                dp[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i < 1001; i ++) {
        for (int j = 1; j < 1001; j ++) {
            mx = max(dp[i][j], mx);
        }
    }
    
    
    cout << mx << '\n';

        while (dp[al][bl]){
        if (dp[al][bl] == dp[al - 1][bl]) {
            al--;
        }    

        else if (dp[al][bl] == dp[al][bl - 1]) {
            bl--;
        }

        else{
            s.push_back(al);
            al--;
            bl--;
        }
    }

        while (!s.empty()) {
        cout << s1[s.back()];
        s.pop_back();
    }


}