#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int k ; cin >> k ;
    int n[k];
    int ans=0;
    for(int i = 0; i < k; i ++){
        cin >> n[i];
        for(int j = 2; j < n[i]; j ++){
            if(n[i]%j==0){
                break;
            }
            if(j==n[i]-1) ans++;
        }
    }
    cout << ans;
}