#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int p(int k, int n) {
    int sum = 0, ret = 0;
    for (int i = 0; i < n; i ++) {
        if (sum + v[i] > k) {
            sum = 0;
            ret ++;
        }
        sum += v[i];
    }

    return ret + 1;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    int mx = 0;
    for (int i = 0; i < n; i ++) {
        mx = max(mx,v[i]);
    }
    int l = mx-1, r = 30004;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        //int sum = 0, ret = 0;
        if (p(mid, n) > m) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << r << "\n";

    int sum = 0;
    int cnt = 0;
    int k = 0;
    
    for (int i = 0; i < n; i ++) {
        if (sum + v[i] > r) {
            cout << cnt << " ";
            sum = 0;
            cnt = sum;
            m --;
        }

        sum += v[i];
        cnt ++;
        if (n - i == m) {
            break;
        }
    }

    cout << cnt << " ";
    m --;
        while (m--) {
            cout << "1 ";
        }

}