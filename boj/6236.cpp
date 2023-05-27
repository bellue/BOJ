#include <bits/stdc++.h>

using namespace std;
long sum;
const int imf = 1e6+6;
const int N = 100005;
int money[N];

 
int mcheck(int k, int n){ // 금액이 k일때의 cnt를 리턴, k에 이분탐색의 값이 들어가면서 cnt가 m보다 작거나 같아지면 cnt 출력
    int cnt = 1;
    int remain = k;
    for (int i = 0; i < n; i ++) {
        if(remain<money[i]){
            cnt ++;
            remain = k;
            remain -= money[i];
        }
        else {
            remain -= money[i];
        }
    }
    
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
        cin >> money[i];
    }

    for (int i = 0; i < n; i ++) {
        sum += money[i];
    }

    int avr=money[0];
    for (int i = 0; i < n; i ++) {
        avr = max(avr,money[i]);
    }
    int res = 0;

    int x;
    bool flag = true;
    while (avr <= sum) {
        res = (avr+sum)/2;
        x = mcheck(res,n);

        // if(x==m) {
        //     cout << avr ;
        //     flag = 0;
        //     break;

        // }
        if(x <= m) {
            //flag = 1;
            sum = res -1;
        }
        else if(x > m) {
            avr = res + 1;
        }
    }
    if(flag) {
        cout << res;
    }

}