#include <iostream>
#include <algorithm>

using namespace std;

void hnoi(int num, int start, int end, int ele) {
    if (num == 1) {
        cout << start  << " " << end << "\n";
    }
    else {
        hnoi(num - 1, start, ele, end);
        cout << start << " " << end << "\n";
        hnoi(num - 1, ele, end, start);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    cout << (1 << n) -1 << "\n";
    hnoi(n, 1, 3, 2);


}