#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
int main(void){
	int N, M, cnt1, cnt2, mini=9999999;
	scanf("%d %d",&M,&N);
	char board[M][N];
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			scanf(" %c",&board[i][j]);
		}
	}
	for(int i=0; i<M-7; i++){
		for(int j=0; j<N-7; j++){
			cnt1 = 0;
			cnt2 = 0;
			//가장 왼쪽위가 B일 경우 
			for(int k=i; k<i+8; k++){
				for(int q=j; q<j+8; q++){
					if((k-i+q-j)%2==0 && board[k][q]=='W')
						cnt1++;
					if((k-i+q-j)%2==1 && board[k][q]=='B')
						cnt1++;	
				}
			}
			for(int k=i; k<i+8; k++){
				for(int q=j; q<j+8; q++){
					if((k-i+q-j)%2==0 && board[k][q]=='B')
						cnt2++;
					if((k-i+q-j)%2==1 && board[k][q]=='W')
						cnt2++;		
				}
			}
			mini = min(mini, cnt1);
			mini = min(mini, cnt2);
		}
	}
    	for(int i=0; i<M-7; i++){
		for(int j=0; j<N-7; j++){
			cnt1 = 0;
			cnt2 = 0;
			//가장 왼쪽위가 B일 경우 
			for(int k=i; k<i+8; k++){
				for(int q=j; q<j+8; q++){
					if((k-i+q-j)%2==0 && board[k][q]=='W')
						cnt1++;
					if((k-i+q-j)%2==1 && board[k][q]=='B')
						cnt1++;	
				}
			}
			for(int k=i; k<i+8; k++){
				for(int q=j; q<j+8; q++){
					if((k-i+q-j)%2==0 && board[k][q]=='B')
						cnt2++;
					if((k-i+q-j)%2==1 && board[k][q]=='W')
						cnt2++;		
				}
			}

            if(mini==min(mini,cnt1)||mini==min(mini,cnt2)){
                cout << i << " " << j << endl; 
            }
		}
	}
	printf("%d", mini);
}