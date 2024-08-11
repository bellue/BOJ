#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 1e6-1;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;

    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        if (x == 1) {
            int k; cin >> k;
            v.push_back(k);
        }
        else if (x == 2) {
            if(v.empty()) cout << "-1" << "\n";
            else{
            int k = v.back(); cout << k << "\n";
            v.pop_back();
            }
        }
        else if (x == 3) {
            cout << v.size() << "\n";
        }
        else if (x == 4) {
            if(v.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if (x == 5) {
            if(v.empty()) cout << "-1" << "\n";
            else {
            int k = v.back(); cout << k << "\n";
            }
        }
    }

}