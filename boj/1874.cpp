#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,tmp;
    vector<int> v;
    cin >> n;
    int k[n];
    int s[n];
    
        for(int i = 0 ; i < n ; i++){
            cin >> k[i];
            s[i]=k[i];
        }
    
        for (int i = 0 ; i < n ; i++){ //k Á¤·Ä 
            for (int j = 0 ; j < n-i ; j++){
                if(k[j]>k[j+1]){
                    tmp=k[j];
                    k[j]=k[j+1];
                    k[j+1]=tmp;
                }
            }
        }

        int x = 0;
        int i = 0;
            while(1){
                if(k[i]!=s[x]){
                v.push_back(k[i]);
                cout << "+" << endl;
                i++;
                }
                else if(k[i]==s[x]){
                    v.pop_back();
                    cout << "-" << endl;
                    x++;
                }
                if(i==n-1){
                    if(v.empty()){
                        break;
                    }
                    else{
                        cout << "NO" << endl;
                        break;
                    }
                }
            }

        
    
}
