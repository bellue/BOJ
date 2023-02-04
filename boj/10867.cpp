#include <iostream>

using namespace std;

int main(){
    int N,ch;
    cin>>N;
    int a[10000]={0,};
    int b[10000]={0,};

    for(int i=0;i<N;i++){
        cin>>ch;

        if(ch>=0){
        a[ch]++;
        }

        if(ch<0){
        b[-ch]++;
        }
    }

    for(int i=1000;i>0;i--){
        if(b[i])
        cout<<-i<<" ";
    }
    for(int i=0;i<=1000;i++){
        if(a[i])
        cout<<i<<" ";
    }
}