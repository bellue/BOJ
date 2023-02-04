#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int little[9];
    int sumall=0;

    for ( int i = 0 ; i < 9 ; i ++){
        cin >> little[i];
        sumall+=little[i];
    }
    
    int x,y;

    for ( int i = 0 ; i < 9 ; i ++){
        int sum=0;
        sum+=little[i];
        for ( int j = i+1 ; j < 9 ; j++){
            sum+=little[j];
            if((sumall-sum)==100){
                x=i;
                y=j;
            }
        }
    }
    int final [9];
    int j=-1;
    for (int i = 0 ; i < 9 ; i ++){
        if(i==x||i==y)continue;
        j++;
        final[j]=little[i];
    }

    sort(final,final+7);
    
    for( int i = 0 ; i < 7 ; i++){
        cout << final[i] << "\n";
    }

}