#include <bits/stdc++.h>
#define a 65

using namespace std;

const int N = 51;
char c[N+1] ;
int alpCnt[26]; // 들어온 알파벳의 개수 체크



int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i ++) {
        //c[i] = s[i];
        alpCnt[(int)s[i]-a] ++;
    }
    //cout << alpCnt[25];

    int returnCnt = 0;
    for (int i = 0; i < 26; i ++) {
        if(alpCnt[i]%2 == 1) {
         returnCnt ++;
        }

        if(returnCnt ==2) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    char res[s.length()]={0,};


    int j = 0;
        for (int i = 0; i < 26; i ++) {
            if (alpCnt[i]%2 == 1) {
                res[s.length()/2] = (char)(i+a);
                alpCnt[i] --;
                i--;
                continue;
            }
            else if(alpCnt[i]!=0) {
                while (alpCnt[i] != 0) {
                    res[j] = (char)(i+a);
                    res[s.length() - j-1] = (char)(i+a);
                    j ++;
                    alpCnt[i] -= 2;
                }
            }
        }
    

    for (int i = 0; i < s.length(); i ++) {
        cout << res[i];
    }
}