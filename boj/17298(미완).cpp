#include <iostream>
#include <vector>

using namespace std;

vector<int> v; // 스택대신 활용

int main(){
    int n;
    cin >> n;
    vector <int> a; //배열 저장

    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    for ( int i = 0 ; i < n ; i++){
        while(!a.empty()&&v.back()<a[i]){
            
        }
    }
}