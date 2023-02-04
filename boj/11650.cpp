#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair <int,int>> v;


int main(){
    int n;
    cin >> n ;

    for ( int i = 0 ; i < n ; i++ ){
        int x,y;
        cin >> x >> y ;
        v.push_back(make_pair(x,y));
    }


    sort ( v.begin() , v.end());

    for ( int i = 0 ; i < n ; i++ ){
        cout << v[i].first << " " << v[i].second << "\n";
        
    }

}