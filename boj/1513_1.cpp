#include <bits/stdc++.h>
 
#define mod 1000007
 
using namespace std;
using pii = pair<int, int>;
 
int n, m, v;
int dp[51][51][51][51];
map<pii, int> funidx;
 
int memo(int r, int c, int last, int cnt);
 
int main()
{
    memset(dp, -1, sizeof dp);
    cin.tie(0); ios::sync_with_stdio(false);
 
    cin >> n >> m >> v;
 
    for (int i = 1; i <= v; ++i)
    {
        int a, b;
        cin >> a >> b;
 
        funidx[{a, b}] = i;
    }
 
    for (int i = 0; i <= v; ++i)
        cout << memo(1, 1, 0, i) << ' ';
}
 
int memo(int r, int c, int last, int cnt)
{
    int &ret = dp[r][c][last][cnt];
 
    if (ret != -1)
        return ret;
 
    ret = 0;
 
    if (funidx.count({r, c}))
    {
        if (last > funidx[{r, c}])
            return ret;
 
        if (r == n && c == m && cnt == 1)
            ret = 1;
 
        if (r < n && cnt > 0)
            ret = (ret + memo(r + 1, c, funidx[{r, c}], cnt - 1)) % mod;
        if (c < m && cnt > 0)
            ret = (ret + memo(r, c + 1, funidx[{r, c}], cnt - 1)) % mod;
    }
    else
    {
        if (r == n && c == m && !cnt)
            ret = 1;
 
        if (r < n)
            ret = (ret + memo(r + 1, c, last, cnt)) % mod;
        if (c < m)
            ret = (ret + memo(r, c + 1, last, cnt)) % mod;
    }
 
    return ret;
}
