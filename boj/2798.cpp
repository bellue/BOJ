#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,M,sum;
    int mx=0;
    int x;
    cin >> N >> M;
    int cards[N];
    for (int i = 0 ; i < N ; i++){
        cin >> cards[i];
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                sum = cards[i] + cards[j] + cards[k];
                if(sum > M){
                    continue;
                }
                if(mx < sum){
                    mx = sum;
                }
            }
        }
    }

    cout << mx;

}