#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> d(1001);
queue<int> q;
int graph[1001][1001];
int node,edge,startnode;

void dfs(int idx) {
    int visited[1001]={0,};
    d.push_back(idx);


    while (!d.empty()){
        idx = d.back(); 

        d.pop_back();
        if(!visited[idx]&&idx)
        cout << idx << ' ';
        visited[idx] = 1;
        for (int i = node; i > 0; i--) {
            if (graph[idx][i] && !visited[i]) {
                d.push_back(i);
            }
        }

    }

}

void bfs(int idx){
    int checknode[1001]={0,};
    q.push(idx);
    checknode[idx]=1;
    while(!q.empty()){
        idx=q.front();
        
        q.pop();
        
        cout<<idx<<" ";
        for(int i=1;i<=node;i++){
            if(!checknode[i]&&graph[idx][i]){
                q.push(i);
                checknode[i]=1;
            }
        }
    }

}


int main(){
    
    cin>>node>>edge>>startnode;
    
    for(int i=0;i<node;i++){
        graph[i][i]=1; // 연결돼있는 노드들은 1로 표시
    }
    
    for(int i=0;i<edge;i++){
        int h,t;
        cin>>h>>t;
        graph[h][t]=1;
        graph[t][h]=1;    
    }
    dfs(startnode);
    cout<<endl;
    bfs(startnode);
   
}
