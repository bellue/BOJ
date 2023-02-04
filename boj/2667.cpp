#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[26][26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, cnt; //����.���� , ������ �� ����
string s;
vector<int> ans; // cnt ����. 
queue<pair<int, int>> q; // bfs���� ���� ����.

void bfs(int x, int y){
    cnt=0;
    map[x][y]=0;

    q.push(pair<int,int>(x,y)); //������ startnode

    while(!q.empty()){
        int new_x=q.front().first;
        int new_y=q.front().second;

        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x=new_x+dx[i];
            int next_y=new_y+dy[i];

                if(next_x>=0&&next_y>=0&&next_x<n&&next_y<n){
                    if(map[next_x][next_y]){
                        map[next_x][next_y]=0;
                        q.push(pair<int,int>(next_x,next_y));
                    }
                }
        }
        cnt++;
    }

    ans.push_back(cnt);

}

int main(){
    cin.tie(0);

    cin>>n;
	for (int i = 0; i < n; i++)
	{
        
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			map[i][j] = s[j] - '0';
	}

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]){
                bfs(i,j);

            }
        }
    }

    sort(ans.begin(),ans.end());

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    
}