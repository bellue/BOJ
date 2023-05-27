#include <bits/stdc++.h>

using namespace std;

const int N = 3073;
//int del = 3;
int s;
char arr[N+1][2*N+1];
char p = '*';

void divide(int x, int y, int n){
    if(n==3){
        arr[y][x] = p;
        arr[y+1][x-1] = p;
        arr[y+1][x+1] = p;
        arr[y+2][x-2] = p;
        arr[y+2][x-1] = p;
        arr[y+2][x] = p;
        arr[y+2][x+1] = p;
        arr[y+2][x+2] = p;
        
        return;
    }

    else{  
    //del = n/2;
    divide(x,y,n/2); // 중앙 삼각형
    divide(x-n/2,y+n/2,n/2); //왼쪽 삼각형
    divide(x+n/2,y+n/2,n/2); //오른쪽 삼각형
    //return;
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);


    int n; cin >> n;

    //fill(&arr[0][0], &arr[N][2*N], ' ');

    divide(n,1,n);


    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= 2*n; j ++) {
            if(!arr[i][j]) {
                cout << " ";
            }
            else {
                cout << arr[i][j];
            }
        }
        cout << '\n';
    }
}