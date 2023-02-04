#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

int roundup(int x,int y){
    if(x%y==0) return x/y;
    if(x%y!=0) return x/y+1;
}

int main(){
    int n,m;
    cin >> n >> m;
    int arr[m-1][2];
    int x,y,set,single;

    for(int i = 0; i < m; i ++){
        cin >> x >> y;
        set = min(set, x);
        single = min(single, y);
    }

    cout << min(min(n/6*set+single*(n%6),n*single),min(roundup(n,6)*set,n*single));


}