#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
vector<int> s;
vector<int> v;

int main() {
    cin >> n >> m;
    for (int i = 0 ;i < m; i ++) {
        int x; cin >> x;
        s.push_back(x);
    }
    v.push_back(s[0]);
    for(int i = 0; i < m; i ++) {
        if(i == m - 1) {
            v.push_back(n - s[i]);
            break;
        }
        v.push_back((s[i + 1] - s[i] + 1)/2);
    }
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << endl;

    for(int x : v) {
        cout << x << " ";
    }


}
/*
x기준으로 좌우 가로등 높이... 
하나씩 늘리면서 체크 최대 10만 n도 가능 nlogn도 가능
그냥 가로등 사이 거리 체크해서 최소거리를 높이로 하면 될듯?
0-첫가로등, 마지막가로등 - n 을 기준으로
*/
