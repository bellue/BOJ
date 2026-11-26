#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    int c[250004];
    int s[250004];
    fill(s, s + n + 1, 0);
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    s[0] = c[0];
    for (int i = 0; i < n - 1; i ++) {
        s[i + 1] = s[i] + c[i + 1]; 
    }
    int Max = s[x - 1]; // x가 5면 인덱스 4까지의 합부터 비교시작.. 4까지의 합은 4
    for(int i = x; i < n; i ++) {
        Max = max(Max, s[i] - s[i - x]);
    }
    int checkm = 0;
    int cnt = 0;
    if(Max == s[x - 1]) cnt ++;
    //cout << cnt << endl << s[x - 1] << endl;
    for(int i = x; i < n; i ++) {
        checkm = max(checkm, s[i] - s[i - x]);
        if(checkm == Max) {
            //cout << i << endl;
            cnt ++;
            checkm = 0;
        }

        
    }
    if(Max == 0) {
        cout << "SAD";
        return 0;

    }
    cout << Max << '\n' << cnt;
}

/*
연속해서 x일동안 최대방문자 -> 누적합?
on으로 누적합 1차원배열은 가능.
누적합 다시 돌면서 최댓값 갱신 -> 최종 최댓값 구하고
해당 max가 몇번인지 한번 더 돌기
*/