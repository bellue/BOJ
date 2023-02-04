#include <iostream>
using namespace std;

int main(){
    int h,m;
    int time;
    cin>>h>>m;
    cin>>time;

    int resh=h;
    int resm=m+time;
    if(resm>=60){
        while(resm>=60){
        resh++;
        resm=resm-60;
        if(resh==24) resh=0;
        }
    }
    cout<<resh<<" "<<resm<<endl;

}
