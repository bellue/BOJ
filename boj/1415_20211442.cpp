#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int cntnum[100005]; // 해당 숫자의 개수
ll dp[500005];
bool pnum[500005]; // 해당 숫자가 소수면 true

vector<int> c; // 중복 없이 사탕가격 저장
//사탕 가격 0이면 예외처리

int main() {
    int n; cin >> n;

    fill(pnum,pnum+500005,true);

    int arr [n] = {0,};
    
    for (int i = 0 ; i < n; i ++) {
        cin >> arr[i];
        if (arr[i]!=0 && !cntnum[arr[i]]){
            cntnum[arr[i]] ++;
            c.push_back(arr[i]);
            continue;
        }

        cntnum[arr[i]]++;
    }

    
    for (int i = 2; i <= sqrt(500005); i ++) {
        if(!pnum[i]) continue;

        for (int j = i*i; j <= 500005; j += i) {
            pnum[j] = false;
        }
    } //소수판별

    // for (int i = 0; i < c.size(); i ++) {
    //     cout << c[i] << " ";
    // }

    dp[0] = 1; dp[500000] = 1;
    
    for (int i = 0; i < c.size(); i ++) {
        for (int j = 500000; j >= 0; j --) {
            for (int k = 1; k <= cntnum[c[i]]; k ++) {
                if(j - k*c[i] < 0)break;
                    dp[j] += dp[j-k*c[i]];
            }
        }
    }


    ll res = 0;

    for (int i = 2; i < 500001; i ++) {
        if(pnum[i]) {
            res += dp[i];
        }
    }

    cout << res*(cntnum[0] + 1);


}

