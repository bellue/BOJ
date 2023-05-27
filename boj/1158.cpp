#include <bits/stdc++.h>

using namespace std;
const int N = 5003;
bool check[N];
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n,k;
    cin >> n >> k;
    
    cout << "<";
    int p = 0;

    for (int i = 0; i < n; i ++) {
        int j = 0;
        while(j!=k) {
            ++p;
            if(p>n) p=p-n;
            if(!check[p]) {
                j++;
            }
        }

        check[p]=1;
        if(i==(n-1)) {
            cout << p; 
        }
        else{
        cout << p << ", ";
        }
    }
    
    cout << ">";

}