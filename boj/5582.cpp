#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int sa[4000][4000]={0,};
//int sb[4000][4000]={0,};
int maxlen=0;

void dp(string a,string b){
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++){
            if(sa[i][j]&&i>0&&j>0){
                sa[i][j]+=sa[i-1][j-1];                
            }
        }
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++){
            maxlen=max(sa[i][j],maxlen);
        }
}
int main(){
    string a,b;
    cin>>a>>b;
        for(int i=0;i<a.size();i++)
            for(int j=0;j<b.size();j++){
                if(a[i]==b[j]){
                    sa[i][j]=1;
                }
            }
    dp(a,b);
    
    cout<<maxlen<<endl;
}