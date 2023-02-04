#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

bool compare(int i , int j ){
    return i>j;
}

int main(){
    string s;
    cin >> s;
    int n[s.size()];
    int k=s.size();
    for(int i = 0 ; i < s.size() ; i ++){
        n[i]=s[i]-'0';
    }
    
    sort(n,n+k,compare);
    int sum=0;

    if(n[k-1]==0){
        for(int i = 0 ; i < k ; i++){
            sum+=n[i];
        }
        if(sum%3==0){
            for(int i = 0 ; i < k ; i ++)cout << n[i];
        }
        else cout << "-1";
    }
    else cout << "-1";

}