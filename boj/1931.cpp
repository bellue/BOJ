#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;
vector<int> m;

int main(){
    int n;
    cin >> n;
    //int time[n][2];
    
    for ( int i = 0 ; i < n ; i ++ ){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(b,a)); //���Ϳ� �ð�ǥ �Է�
    }

    int count=1;

    sort(v.begin(),v.end()); //����ð��� ���� �ð�ǥ ����(first�� ����ð���)


        int t=v[0].first ;
        for ( int i = 1 ; i < n ; i ++ ){
            if(t<=v[i].second){
                t=v[i].first;
                count ++;
                continue;
            }

        }
        cout << count ;
    


}