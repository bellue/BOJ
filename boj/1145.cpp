#include <iostream>
using namespace std;
int main(){
    int d[5];
    for(int i=0;i<5;i++){
        cin>>d[i];
    }
    int k=0;
    
    while(++k){
        int check=0;
        for(int i=0;i<5;i++){
            if(k%d[i]==0)check++;
        }
        if(check>=3)break;
    }
    cout<<k;
}