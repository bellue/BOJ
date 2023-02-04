#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v,ans;
int cnt;

int main() {
   ios::sync_with_stdio(false); cin.tie(nullptr);
    int n , m ;
    cin >> n >> m;

    for(int i = 0; i < n+m; i ++ ){
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < v.size(); i ++){
        if(v[i]==v[i+1]){
            cnt ++;
            ans.push_back(v[i]);
        }
    }

    cout << cnt << endl;
    for(int i = 0; i < ans.size(); i ++){
        cout << ans[i] << endl;
    }

}
    