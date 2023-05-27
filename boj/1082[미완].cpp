#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int,int>> p;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,m;
    //string price[n];
    cin >> n;

    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        p.push_back(pair<int,int>(i,x)); // 가격,번호 순으로 저장
    }

    sort(p.begin(),p.end());
    
    string ret;

    cin >> m;


}