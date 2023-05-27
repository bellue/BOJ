#include <iostream>

using namespace std;

int power(int a){
    a*=a;
    return a;
}

int main(){
int arr[100];
int f[100];
int a,b,c;
cin >> a >> b >> c;
long long r = 1;
//int r=a%c; //첫번째 나머지

r=(r*a)%c; //나머지 구하는 공식
int k = 0;
while(1!=b){
    if(b%2==1) {
        b=(b-1)/2;
        arr[k]=b;
        f[k]=-1;
        k++;
    }
    else {
        b=b/2;
        arr[k]=b;
        f[k]=0;
        k++;
    }
}
}


b를 규칙에 따라 2로 나누거나 -1 2 로 나눔
배열에 담김
배열에 담긴걸 보고 나머지 연산 시작
배열에 담긴게 4 2 1이면
b가 1일때의 r을 구하고
2일때의 r을 구하고