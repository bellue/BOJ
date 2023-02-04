#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

int main(){
    int n;
    cin >> n ;
    vector<string> tmp(n-1);
    int num[n];
    int k[4]; //  + - * / 순서
    for (int i = 0 ; i < n ; i ++) {
        cin >> num[i];
    }
    for (int i = 0 ; i < 4 ; i ++) {
        cin >> k[i];
    }

    int mx,mn;
    for (int i = 0 ; i < n-1 ; i ++){ //v에 +부터 순서대로 push -> 브루트포스로 모든 경우 해보자
        if(k[0]){
            v.push_back("+");
            k[0]--;
        }
        else if(k[1]){
            v.push_back("-");
            k[1]--;
        }
        else if(k[2]){
            v.push_back("*");
            k[2]--;
        }
        else if(k[3]){
            v.push_back("/");
            k[3]--;
        }
    }
    string s;
    int sum=0;
    for(int i = 0 ; i < n-1 ; i ++)cout << v[i] << " ";
    /*
    do{
        for(int i = 0 ; i < n-1 ; i ++){
            tmp[i]=v[i];
        }
        int a[n];
        for( int i = 0 ; i < n ; i ++){
            a[i]=num[i];
        }
        for( int i = 0 ; i < n-1 ; i ++){
            tmp.pop_back();
            if(s=="+"){
                a[i]+=a[i+1];
            }
            else if(s=="-"){
                a[i]-=a[i+1];
            }
            else if(s=="*"){
                a[i]*=a[i+1];
            }
            else if(s=="/"){
                a[i]/=a[i+1];
            }
        }
        mx=max(a[0],mx);
        mn=min(a[0],mn);
    }while(next_permutation(v.begin(),v.end()));

    cout << mx << "\n" << mn ;
    */
}


// 