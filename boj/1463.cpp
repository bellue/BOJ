#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(1000000);
    dp[1] = 1;
    dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        if (dp[i % 2] != 0 && dp[i % 3] != 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else if (dp[i % 3] == 0 && dp[i % 2] == 0)
        {
            dp[i] = min(dp[i / 3], dp[i / 2]) + 1;
        }
        else if (dp[i % 2] == 0)
        {
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        }
        else if (dp[i % 3] == 0)
        {
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        }
    }
    if(n==1)cout<<0;
    else
    cout << dp[n] << endl;
}