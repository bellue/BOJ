#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int,int>> v; //y������ ���� y������ x�� �Ǵ�.
int main(){
    int n;
    cin >> n;
    int x,y;
    for(int i = 0 ; i < n ; i ++){
        cin >> x >> y;
        v.push_back(make_pair(y,x)); 
    }

    sort(v.begin(),v.end());

    for(int i = 0 ; i < n ; i ++){
        cout << v[i].second << " " << v[i].first << "\n";
    }

}