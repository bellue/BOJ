#include <iostream>
#include <queue>

using namespace std;

int N,M,cnt=0;
int check[1002]={0,};
int graph[1001][1001]={0,}; //노드 1번부터 시작
queue<int> q;

void bfs(int idx){

    q.push(idx);//startnode
    check[idx]=1;
    while(!q.empty()){
        idx=q.front();
        
        q.pop();
        
        //cout<<idx<<" ";
        for(int i=1;i<=N;i++){
            if(!check[i]&&graph[idx][i]){
                q.push(i);
                check[i]=1;
            }
        }
    }

}

int main(){
    cin.tie(0);
    cin>>N>>M;

    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    for(int i=1;i<N+1;i++){
        if(!check[i]){
            bfs(i);
            cnt++;
        }

    }

    cout<<cnt<<endl;
    

}