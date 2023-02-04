#include <iostream>
#include <queue>

using namespace std;

bool visit[100005];
int n,k;

int bfs(int a){
    queue<pair<int,int>> q;
    q.push(make_pair(a,0));
    visit[a]=1;

    while(!q.empty()){
        int x=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(x==k){
            cout<<cnt;
            break;
        }
        if(x+1>=0&&x+1<100001){
            if(!visit[x+1]){
                visit[x+1]=1;
                q.push(make_pair(x+1,cnt+1));
            }
        }
        if(x-1>=0&&x-1<100001){
            if(!visit[x-1]){
                visit[x-1]=1;
                q.push(make_pair(x-1,cnt+1));
            }
        }
        if(x*2>=0&&x*2<100001){
            if(!visit[x*2]){
                visit[2*x]=1;
                q.push(make_pair(x*2,cnt+1));
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin>>n>>k; //n에서 k까지 갈 수 있는 최단경로
    bfs(n);

}