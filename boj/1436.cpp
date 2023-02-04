#include <iostream>

using namespace std;

int main() {
    int n,tmp,k=1;
    cin >> n;

    while(n){
        k++;
        tmp=k;
        while(tmp){
            if(tmp%1000==666){
                n--;
                break;
            }
            else{
                tmp/=10;
            }
        }
    }

    cout << k;
}