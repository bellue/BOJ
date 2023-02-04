#include <iostream>
using namespace std;

int main(){
    int size,temp=0;
    cin>>size;
    int m[size];
    for(int i=0;i<size;i++){
        cin>>m[i];        
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(m[j+1]<m[j]){
                temp=m[j+1];
                m[j+1]=m[j];
                m[j]=temp;
            }
        }
    }

    cout<<m[0]*m[size-1]<<endl;

}