#include <iostream>

using namespace std;
    int N,M;
    int A[51][51];
    int B[51][51];

void changer(int n, int m){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
        if(A[n+j][m+i]==0) A[n+j][m+i]=1;
        else A[n+j][m+i]=0;
        }
    }
    
}

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%1d",&A[i][j]);
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%1d",&B[i][j]);
        }
    }
        if( N < 3 || M < 3){
        for(int i = 0; i < N; i ++){
            for( int j = 0; j < M; j ++){
                if(A[i][j]!=B[i][j]){
                    cout << "-1";
                    return 0;
                }
            }
        }
        }
    int sum = 0;
    int cnt = 0;
    bool flag = true;
    while(flag&&cnt<N-2){
        for (int i = 0; i < M-2; i++){
            if(A[cnt][i]==B[cnt][i]){
                continue;
            }
            else{
                changer(cnt,i);
                sum ++;
            }
        }

        if(A[cnt][M-2]==B[cnt][M-2]&&A[cnt][M-1]==B[cnt][M-1]){
            cnt ++;
            continue;
        }
        else{
            flag = false;
        }
    }
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            if(A[i][j]!=B[i][j]){
                flag =false;
                break;
            }
        }
    }
    // for ( int i = 0 ; i < N; i ++){
    //     cout << endl;
    //     for( int j = 0; j < M; j++){
    //         cout << A[i][j] << " ";
    //     }
    // }
    // cout << endl << sum << endl;
    if(flag==true) cout << sum;
    else cout << "-1";
    

}