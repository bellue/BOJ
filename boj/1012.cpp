#include <iostream>
#include <queue>

using namespace std;

int M,N,cnum,cnt=0;
int k[50][50]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> q;



void bfs(int x,int y){
    cnt++;
    q.push(pair<int,int>(x,y));
    k[x][y]=0;

    while(!q.empty()){
        int now_x=q.front().first;
        int now_y=q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int next_x=now_x+dx[i];
            int next_y=now_y+dy[i];
                if(next_x>0&&next_y>0&&next_x<M&&next_y<N){
                    if(k[next_x][next_y]){
                        q.push(pair<int,int>(next_x,next_y));
                        k[next_x][next_y]=0;
                    }
                }
        }
    }
}

int main(){ //목표: 지렁이수
    int tcase;
    cin.tie(0);

    cin>>tcase;


    while(tcase--){
        cnt=0;
        int x,y;
        cin>>M>>N>>cnum;
        for(int i=0;i<cnum;i++){
            cin>>x>>y;
            k[x][y]=1;
        }

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){    
                if(k[i][j]){
                    bfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
    }
    
}