#include <iostream>
#include <ctime>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    time_t start, finish;
    double duration;
    start = time(NULL);


    finish = time(NULL);
    duration = (double)(finish - start);
    cout << duration << "s" << endl;

}