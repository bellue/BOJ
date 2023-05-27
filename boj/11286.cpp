#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
 
    int N;
 
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (!q.empty()) {
                cout << q.top().second << '\n';
                q.pop();
            }
            else { 
                cout << 0 << '\n'; 
            }
        }
        else {
            q.push({ abs(tmp),tmp }); //first에 절대값을, second에 실제 값을
        }
 
    }
    return 0;
}
