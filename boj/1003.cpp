#include <iostream>
using namespace std;
int res[50];
int fibonacci(int n);
int main(){
    int tcase;
    cin>>tcase;
    while(tcase--){
        int m;        
        cin>>m;
        fibonacci(m);
        if(m==0)cout<<"1 0"<<endl;
        else if(m==1)cout<<"0 1"<<endl;
        else cout<<res[m-1]<<" "<<res[m]<<endl;
    }
}
int fibonacci(int n) {
    res[0]=0;
    res[1]=1;
    
    for(int i=2;i<=n;i++){
        res[i]=res[i-1]+res[i-2];
    }
    return 0;
}