#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int sp[n][2];
    int d[n];

    for (int i = 0 ; i < n ; i++){
        cin >> sp[i][0] >> sp[i][1];
    }

    for (int i = 0 ; i < n ; i++){
        int k = 0;
        for ( int j = 0 ; j < n ; j++){
            if(sp[i][0]<sp[j][0] && sp[i][1]<sp[j][1]){
                k++;
            }
        }
        d[i]=k+1;
    }

    for (int i = 0 ; i < n ; i++) cout << d[i] << " ";
}