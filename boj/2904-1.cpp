#include <bits/stdc++.h>

using namespace std;

int N;
//int water[1003];
int divisor[1000006]; // 약수의 지수의 개수 저장
//int nd[102][1000006];
int main(){
    cin >> N;
    int num[N];
    
    for(int i = 0; i < N; i ++){
        cin >> num[i];
    }

    for(int i = 0; i < N; i ++){
        int water[num[i]+1];  // 가능한 소수 저장
        
        for(int a = 1; a <= num[i]; a ++){
            water[a] = a;
        }
        for(int j = 2; j <= sqrt(num[i]); j ++){
            if(!water[j]){
                continue;
            }

            for(int k = j*j; k <= num[i]; k +=j){
                water[k] = 0;          // 해당 숫자의 약수가 될 수 있는 소수들 판별별
            }

        }

        // cout << water[2] <<" "<< num[i] << " " << num[i]%water[2] << "\n";
        
        for(int l = 2; l <=num[i]; l++){
            if(num[i]==1)break;
            if(water[l]&&!(num[i]%water[l])){
                v.push_back(x);
                num[i]/=water[l];
                divisor[l]++;
                l--;
                continue;
            }
        }
        

        //cout << divisor[3] << endl;
           
        
    }
    cout << nd[1][0];


    // int gcd=1;
    // int cnt=0;
    
    
    // for(int i = 2; i < 1000005; i ++){        
    //     if(!divisor[i]) continue;
    //     //cout << divisor[i] << endl;
    //     gcd *= pow(i,divisor[i]/N);
    // }
    
    // for(int k = 0; k < N; k ++){
    //     for(int i = 2; i < 1000005; i ++){
    //         if(!divisor[i]) continue;
        
        
    //         if(nd[k][i] < divisor[i]/N){
    //             cnt +=divisor[i]/N-nd[k][i];
    //         }
    //     }
    // }
    // cout << gcd << " " << cnt;
}