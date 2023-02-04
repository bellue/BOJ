#include <iostream>

using namespace std;

int p[100][100];
int N;
int main(){
    int cnt=0;
    int x,y;
    cin>>N;
    while(N--){
        cin>>x>>y;
        for(int i=y;i<y+10;i++){
            for(int j=x;j<x+10;j++){
                if(!p[i][j]){
                    cnt++;
                    p[i][j]=1;
                }
            }
        }
    }
    cout<<cnt;
}
