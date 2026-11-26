#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;
    int cnt = 1;
    for (int i = 0; i < s.size(); i ++) {
        while(1) {
            string c;
            for(int j = i; j < s.size(); j ++){
                if(s[i] == cnt){
                    break;
                } else{
                    s[i] += s[j];
                }
            }
        }
    }
    cout << cnt;

}
/*
1부터 숫자 하나씩 늘려가면서 문자열에 해당하는 수 빼기.
수 여러개 뺄 수 있으면 더 빼기.

*/