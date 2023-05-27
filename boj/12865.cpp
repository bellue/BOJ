#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int P[101][100001];
int v[101][2];

int main() {
   ios::sync_with_stdio(false); cin.tie(nullptr);

   cin >> n >> k;
   
   for(int i = 0; i < n; i ++){
      int x,y;
      cin >> x >> y;
      v[i][0]=x;
      v[i][1]=y;
   }

   for( int i = 1; i <= n; i ++){
      for( int j = 1; j <= k; j ++){
         if(j<v[i-1][0]){
            P[i][j]=P[i-1][j];
         }
         else{
            P[i][j]=max(v[i-1][1]+P[i-1][j-v[i-1][0]],P[i-1][j]); // 새로운 것의 가치 + 
         }
         }
      }

   int mx=0;

   for( int i = 1; i <= n; i ++){
      for( int j = 1; j <= k; j++){
         mx = max(P[i][j],mx);
      }
   }

   cout<<mx;
   }
   