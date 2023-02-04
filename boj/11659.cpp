#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n,m;
    cin >> n >> m ;
    int arr[n+1]={0,};
    for( int i = 0; i < n; i ++ ){

        int k;
        cin >> k;

        if(i==0){
            arr[1]=k;
        }
        else
        arr[i+1]=arr[i]+k;
    }

    while(m--){
        int a,b;
        cin >> a >> b;
        cout << arr[b]-arr[a-1] << "\n";
    }
}