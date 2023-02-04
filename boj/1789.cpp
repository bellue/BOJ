#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int main(){
    long n,sum=0;
    cin >> n;
    int i=1;
    int count=0;
    while(n>sum){
       
        sum+=i;
        count ++;
        i++;
    }

        if(n==sum)cout << count;
        else{
            cout << count-1 ;
        } 
    


}
