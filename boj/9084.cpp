#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
   ios::sync_with_stdio(false); cin.tie(nullptr);

   int t; cin >> t;

   while(t--){
    int dp[10001]={0,};
    int n; cin >> n;
    int p[n+1];
    for( int i = 1; i <= n; i ++){
        cin >> p[i];
    }
    int tot; cin >> tot;

    dp[0]=1;

    for(int i = 1; i <= n; i ++){
        for(int j = p[i]; j <= tot; j ++){
            dp[j]+=dp[j-p[i]];
            }
        }

    
        cout << dp[tot] << endl;
    }
   
}