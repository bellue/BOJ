#include <bits/stdc++.h>
using namespace std;

const int m = 1e+6;

int cnt[m], arr[m];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    // int N; cin >> N;
    // for (int i = 0; i < N; i ++){
    //     cin >> 
    // }
    
    for (int i = 0; i < n; i++) {
        int cal = arr[i];
        for (int j = 2; j <= arr[i]; j++) {
            while (cal % j == 0) {
                cal /= j;
                cnt[j]++;
            }
        }
    }
    
    int ans = 1;
    vector<int> facs;
    for (int i = 2; i < m; i++) {
        if (cnt[i] / n) {
            for (int j = 0; j < (cnt[i] / n); j++) {
                facs.push_back(i);
                ans *= i;
            }
        }
    }

    int ans_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : facs) {
            if (arr[i] % x) ans_cnt++;
            else arr[i] /= x;
            cout << arr[i] << " ";
        }
    }
    printf("\n%d %d", ans, ans_cnt);
}