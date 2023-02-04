#include <iostream>
using namespace std;

int main(){
    long long N,F;
    cin>>N>>F;
    N=N-(N%100);
    int res=0;
    while(N%F!=0){
        N++;
        res++;
    } 
    if(res<10) cout<<"0"<<res<<endl;
    else cout<<res<<endl;
}

