#include <iostream>
using namespace std;
int main(){
    long long tcase;
    cin>>tcase;
    while(tcase--){
        long long n,m,temp=1;
        long long ans=1;
        cin>>n>>m;
    
        for(int i=m;i>m-n;i--){
            ans*=i;
            ans/=temp++;
        }

        cout<<ans<<endl;
    }
}