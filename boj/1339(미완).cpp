#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;

int ten(int a){
    if(a==0) return 1;

    for(int i = 0 ; i < a ; i ++ ){
        a*=10;
    }

    return a;
}

int main(){
    int n,sum=0 ;
    cin >> n;

    int a[27];
    string s[n];
    int check [10]={0,1,2,3,4,5,6,7,8,9}; //a���� �����ؼ� �ش� ���ĺ��� ���� �����ƴ��� üũ
    int size[n];

    for ( int i = 0 ; i < n ; i ++ ){
        cin >> s[i];
        size[i]=s[i].size();
    }

    for ( int i = 0 ; i < n ; i ++){
        for ( int j = s[i].size() ; j > 0 ; j ++){
            a[s[]]
        }
    }




    
}