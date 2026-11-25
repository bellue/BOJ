#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, student;
int s[103];
vector<pair<int, int>> v;

int main() {
    cin >> n;
    fill(s, s + 103, -1);
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    cin >> student;
    for (int i = 0; i < student; i ++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    reverse(v.begin(), v.end());

    while(!v.empty()) {
        int x = v[v.size() - 1].first; // 성별
        int y = v[v.size() - 1].second; // 받은 자연수
        v.pop_back();

        if(x == 1) { // 남자
            for(int i = y - 1; i < n; i  += (y)) {
                if(s[i]) {
                    s[i] = 0;
                }else {
                    s[i] = 1;
                }
            }
        }
        if(x == 2) {
            for (int i = 0; i < n; i ++) {
                if(y - 1 - i < 0 || y - 1 + i >= n) break;
                if(s[y - 1 - i] == s[y - 1 + i]) {
                    if(s[y - 1 - i]) {
                        s[y - 1 - i] = 0;
                        s[y - 1 + i] = 0;
                    } else{
                        s[y - 1 - i] = 1;
                        s[y - 1 + i] = 1;
                    }
                } else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        cout << s[i] << " ";
    }
}   