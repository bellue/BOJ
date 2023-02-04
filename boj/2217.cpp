#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n ;
    int r[n];
    for ( int i =0  ; i < n ; i ++ ){
        cin >> r[i];
    }

    int kg,mx=0;

    sort(r,r+n);

    for(int i = 0 ; i < n ; i ++){
        kg=(n-i)*r[i];
        mx=max(kg,mx);
    }

    cout << mx;

}