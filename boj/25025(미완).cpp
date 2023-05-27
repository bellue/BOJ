#include <iostream>

using namespace std;

int q(int a,int n){
    for(int i = 0 ; i < n ; i ++ ){
        a=a*a; //f(a)일때
    }
    if(a==0)return 1;
    else return a;
}

int main(){
    int n,p;
    cin >> n >> p;
    int a[n+1];

    for( int i = n ; i >=0 ; i -- ){
        cin >> a[i]; //각 계수 입력받음
    }
    
    
    for(int i = 0 ; i < p ; i ++ ){
        int sum = 0;
        for(int j = 0 ; j < n+1 ; j++ ){
            
            sum+=a[j]*q(i,j);
        }
        cout << sum%p << "\n";
    }

}