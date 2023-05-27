#include <bits/stdc++.h>

using namespace std;

const int m = 1000006;

int divisor[m];

int main(){
    int N ;
    cin >> N;
    int num[N];
    
    for(int i = 0; i < N; i ++){
        cin >> num[i];
    }
    int arr[N];
    for(int i = 0; i < N; i ++){
        arr[i] = num[i];
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

        for(int l = 2; l <=num[i]; l ++){
            if(num[i]==1)break;
            if(water[l]&&!(num[i]%water[l])){
                num[i]/=water[l];
                divisor[l]++;
                l--;
                continue;
            }
        }
    }
    vector<int> v;
    int gcd = 1;
    for(int i = 2; i < m; i ++){
        if (divisor[i]/N){ // divisor 이 0이 아니고 나눴을 때 값이 1 이상일 때
            for(int j = 1; j <= (divisor[i]/N); j ++){
                v.push_back(i);
                gcd *= i;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < v.size(); j ++){
            if(arr[i]%v[j]) cnt ++;
            else arr[i] /= v[j];
        }
    }

    cout  << gcd << " " << cnt;

}