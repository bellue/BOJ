#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int zero,nzero;
int p[200][200];

void check(int x,int y,int size){
    int nowc=p[x][y];
    bool flag=true;

    for( int i = x; i < x+size/2; i ++){
        for( int j = y; j < j+size/2; j ++){
            if(p[i][j]!=nowc){
                flag==false;
                break;
            }
        }
    }
    if(!flag){
        
    }


}

int main() {
   ios::sync_with_stdio(false); cin.tie(nullptr);

   int n; cin >> n;
   for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
        int x; cin >> x;
        p[i][j]=x;
    }
   }
   check(1,1,n);


}