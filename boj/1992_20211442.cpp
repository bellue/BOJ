#include <bits/stdc++.h>

using namespace std;


int arr[64][64];


void dc (int x,int y,int s) {
    int temp = arr[x][y];

    for (int i = x; i < x+s; i ++) {
        for (int j = y; j < y+s; j ++) {
            if(arr[i][j]!=temp) {
                cout << "(";
                dc(x,y,s/2);
                dc(x,y+s/2,s/2);
                dc(x+s/2,y,s/2);
                dc(x+s/2,y+s/2,s/2);
                cout << ")";
                return;
            }
        }
    }

    cout << temp;
}

int main() {
    
    int n; cin >> n;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            scanf("%1d",&arr[i][j]);
        }
    }

    dc(0,0,n);
    
    
}