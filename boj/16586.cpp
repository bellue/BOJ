#include <iostream>
#include <list>
#include <algorithm>


using namespace std;

int main(){
    int n;
    cin >> n;
    list<int> lt(n);

    for( int i = 0 ; i < n ; i ++ ){
        lt.push_back(i+1);
    }
    
    

}