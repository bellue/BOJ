#include <iostream>
#include <vector>

using namespace std;

int dp[10004]={1,2,4,0,};
//vector<int> v;

int main(){
    int tcase;
    cin>>tcase;

    for(int i=3;i<11;i++){
        dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
    }
    
    while(tcase--){
        int k;
        cin>>k;
        cout<<dp[k-1]<<endl;

    }
}