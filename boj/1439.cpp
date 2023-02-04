#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    bool f=true;
    int k=s.size();

    int count0=0,count1=0;
        for(int i = 0 ; i < k ; i ++){
            if(s[i]=='0'&&f){
                count0 ++;
                f=false;
                continue;
            }
            else if(s[i]=='1') f=true;
        }
    f=true;
        for(int i = 0 ; i < k ; i ++){
            if(s[i]=='1'&&f){
                count1 ++;
                f=false;
            }
            else if(s[i]=='0') f=true;
        }
    
    int mn=min(count0,count1);
    cout << mn ;
}