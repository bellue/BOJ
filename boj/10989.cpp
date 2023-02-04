#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector <int> v;
    int k; cin >> k;
    for( int i = 0; i < k; i ++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for( int i = 0; i < k; i ++){
        cout << v[i] << "\n";
    }
}