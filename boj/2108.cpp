#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main(){
    int n, temp, mean, mode = 0, min, max = 0;
    bool flag = false;
    cin>>n;
 
    vector<int> v(n);
    vector<int> v2(8001, 0);
 
    for(int i=0; i<n; i++){
        cin>>v[i];
        mean += v[i];
        temp = (v[i] <= 0) ? abs(v[i]) : v[i] + 4000;
        v2[temp]++;
        if(v2[temp] > max)
            max = v2[temp];
    }
    sort(v.begin(), v.end());
 
    for(int i = -4000; i < 4001; i++){
        temp = i <= 0 ? abs(i) : i+4000;
        if(v2[temp] == max){
            mode = i;
            if(flag)
                break;
            flag = true;
        }
    }

    cout<<round(mean/(double)n)<<'\n';
    cout<<v[round(n/2)]<<'\n';
 
    cout<<mode<<'\n';
    min = v[0];
    max = v[v.size()-1];
    cout<<max - min<<'\n';
}