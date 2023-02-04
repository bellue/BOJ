#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int m,n,cnt;
int graph[1003][1003];
int visit[1003][1003];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> q;

void bfs(int si,int sj){
    q.push(make_pair(si,sj));
    visit[si][sj]=1;

    while(!q.empty()){
        int now_x=q.front().first;
        int now_y=q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int next_x=now_x+dx[i];
            int next_y=now_y+dy[i];

            if(next_x>0&&next_y>0&&next_x<1000&&next_y<1000){
                if(visit[next_x][next_y]&&!graph[next_x][next_y]){
                    visit[next_x][next_y]=1;
                    graph[next_x][next_y]=graph[now_x][now_y]+1; //graph 값 중 가장 큰값이 최종값
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
    }
}

int main(){
    cin>>m>>n; //가로,세로

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j]) visit[i][j]=1; //익은토마토(1),빈칸(-1) 이면 visit 1로 바꿔줌
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==0&&visit[i][j]==0){
                bfs(i,j);
            }
        }
    }


    
}