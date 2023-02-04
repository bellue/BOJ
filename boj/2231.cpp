#include <iostream>

using namespace std;

int main(){
    int N,ch,sum=0;
    cin >> N;

    for ( int i = 0 ; i < N ; i++){
        sum = i;
        ch = i;

        while (ch){
            sum+=ch%10;
            ch /= 10;
        }

        if( N==sum ){
            cout << i;
            return 0;
        }
    }

    cout << "0";
}