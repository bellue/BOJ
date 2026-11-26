#include <iostream>
#include <string>

using namespace std;

int n, k;
int c[200005]; // 0이면 사람 1이면 햄버거 -1이면 먹은버거

int main() {
    cin >> n >> k;
    const int N = n;

    
    string s;
    cin >> s;
    for (int i = 0; i < n; i ++) {
        if(s[i] == 'P') {
            c[i] = 0; 
        }else {
            c[i] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        bool flag = true;
        for(int j = k; j > 0; j --) {
            if(c[i] == 0) {
                if(c[i - j] == 1 && i - j >= 0) {
                    c[i - j] = -1;
                    cnt ++;
                    flag = false;
                    break;
                } else continue;
            }
        }
        if(flag) {
            for (int l = k; l > 0; l --) {
                if(c[i] == 0){
                    if(c[i + l] == 1 && i + l < n) {
                        c[i + l] = -1;
                        cnt ++;
                        break;
                    }
                    else continue;
                }
            }
        }
        
    }
    // for (int i = 0; i < n; i ++) {
    //     cout << c[i] << " ";
    // }
    cout << cnt;
}

/*

*/