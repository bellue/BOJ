#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int dp[3][200001];

int main(){

int tcase;
cin >> tcase;
while(tcase--){
    int n;
    cin >> n;

    int arr[2][n+1];
    //dp[0][0]=dp[1][0]=0;
    for(int i = 0; i < 2; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }

    for(int i = 2; i <= n; i ++){
        dp[0][i] = arr[0][i]+max(dp[1][i-1],dp[1][i-2]);
        dp[1][i] = arr[1][i]+max(dp[0][i-1],dp[0][i-2]);
    }

    cout << max(dp[0][n],dp[1][n]) << "\n";

}

}