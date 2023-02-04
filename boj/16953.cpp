#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int main() {
   ios::sync_with_stdio(false); cin.tie(nullptr);

    int x,y; cin >> x >> y;
    int count = 0;
    bool flag=true;

    while(x!=y){
        if(x>y){
            cout << "-1";
            flag=false;
            break;
        }


        if((y-1)%10==0){
            y=(y-1)/10;
            count++;
        }
        else if(y%2==0){
            y=y/2;
            count++;
        }
        else{
            cout << "-1";
            flag=false;
            break;
        }
    }
    if(flag)
    cout << count+1 ;
}