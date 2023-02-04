#include <iostream>

using namespace std;

int main() {
   ios::sync_with_stdio(false); cin.tie(nullptr);

    float n,l;
    cin >> n >> l ;
    float x=0;
    float i;
    bool flag=false;
    // if(n/l==(int)(n/l))
    // cout << n/l-(int)(n/l) << endl;
    for(i = l; i < 101; i ++){
        if(((n/i-(i-1)/2.0)==(int)(n/i-(i-1)/2.0))&&(n/i-(i-1)/2.0)>0){
            x= (int)(n/i-(i-1)/2.0);
            for(int j = 0; j < i; j++) cout << x+j << " ";
            flag=true;
            break;
        }

    }
   if(!flag&&(n/i-(i-1)/2.0)<0) cout << "-1";
}