#include <iostream>
#include <vector>

using namespace std;

vector<int> v; // ���ô�� Ȱ��

int main(){
    int n;
    cin >> n;
    vector <int> a; //�迭 ����

    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    for ( int i = 0 ; i < n ; i++){
        while(!a.empty()&&v.back()<a[i]){
            
        }
    }
}