#include <iostream>
#include <map>

using namespace std;
map<int, int> m1;
map<int, int> m2;
int main() {
    int n;
    int origin[100005];
    int m;
    int nex[100005];
    cin >> n;
    for (int i = 0;i < n; i ++) {
        int a; cin >> a;
        m1[a] = 1;
    }
    cin >> m;
    for (int j = 0; j < m; j ++) {
        int a; cin >> a;
        if(m1.count(a)) {
            cout << "1" << endl;
        }else {
            cout << "0" << endl;
        }
    }
    

}