#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;

    while(t--){
        int a,b;
        cin >> a >> b;
        if(a>b){
            int x;
            x=b; b=a; a=x;
        }

        while((b-a)>=a){
            
            b/=2;
        }

        while (a != b) { // 2.
            if(a > b){
                a/=2;
                   if(a == b) break;
                   b /= 2;
                }
                else{
                    b /=2;
                    if(a == b) break;
                    a/=2;
                }
            }

            cout << a*10 << "\n";

    }

   
}