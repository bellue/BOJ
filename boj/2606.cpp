#include <iostream>
#include <queue>

using namespace std;

int node;
queue<int> q;
int graph[101][101]={0,};

int bfs(int num){
    int idx;
    int checknode[101]={0,};
    q.push(1);
    checknode[1]=1;
    while(!q.empty()){
        idx=q.front();
        q.pop();
        
        
        for(int i=1;i<=node;i++){
            if(!checknode[i]&&graph[idx][i]){
                q.push(i);
                checknode[i]=1;
                num++;
            }
        }
    }
    return num;
    
}

int main(){
    int friendnode,num=0;
    cin>>node>>friendnode;
    int h,t;
    for(int i=0;i<friendnode;i++){
        cin>>h>>t;
        graph[h][t]=1;
        graph[t][h]=1;
    }
    num=bfs(num);
    cout<<num<<endl;

}