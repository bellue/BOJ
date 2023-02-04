#include <iostream>

using namespace std;

int main(){
    int n,k,sum=0;
    cin >> n >> k;
    int a[n];
    int ch;

    for ( int i = 0 ; i < n ; i++) cin >> a[i];

    for( int i = n-1 ; i >= 0 ; i--){
            sum+=k/a[i];
            k%=a[i];
        
    }
    cout << sum ;
}