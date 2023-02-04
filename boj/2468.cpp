#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int graph[102][102];
int check[102][102];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<int> v; //벡터에 저장해서 최대 안전구역 구할예정
queue<int> q;

void bfs(int startnode){

}
int main(){
    int n,m=0;
    int count=0;
    cin>>n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
            m=max(graph[i][j],m);
        }
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++){
                if(graph[i][j]<=m){
                    check[i][j]=1;
                }
                v.push_back(count);
                count=0;
            }
        
    }
}