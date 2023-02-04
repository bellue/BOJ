#include <iostream>
#include <queue>

using namespace std;

int M,N,cnt=0;
int w,h;
int graph[50][50]={0,};
int checknode[50]={0,}; //필요없을수도?
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
queue<pair<int,int>> q;

void bfs(int x,int y){
    q.push(pair<int,int>(x,y));
    graph[x][y]=0;
    while(!q.empty()){
        int now_x=q.front().first;
        int now_y=q.front().second;
        
        q.pop();
        
        for(int i=0;i<8;i++){
            int next_x=now_x+dx[i];
            int next_y=now_y+dy[i];
            if(next_x>0 && next_y>0 && next_x<w && next_y<h){
                    if(graph[next_x][next_y]){
                        //cout<<i<<endl;
                        graph[next_x][next_y]=0;
                        q.push(pair<int,int>(next_x,next_y));
                    }
            }
        }
        
    }

}


int main(){
    
    while(1){
        cin>>w>>h;
        if(!w&&!h) break;
        graph[50][50]={0,};
        checknode[50]={0,};
        cnt=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int x;
                cin>>x;
                graph[i][j]=x;
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(graph[i][j]){
                    bfs(i,j);
                    cout<<i<<" "<<j<<endl;
                    cnt++;
                }
            }
        };
        cout<<cnt<<endl;

    }
}