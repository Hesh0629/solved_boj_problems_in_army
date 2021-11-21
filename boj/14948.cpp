#include<bits/stdc++.h>
using namespace std;
int n,m,table[104][104],vis[2][102][102];
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},super_x[4]={0,0,-2,2},super_y[4]={-2,2,0,0};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(table,-1,sizeof(table));
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>table[i][j];
      vis[0][i][j]=1000000001;
      vis[1][i][j]=1000000001;
    }
  }
  queue<pair<int,int>>q;
  q.push({1,1});
  vis[0][1][1]=table[1][1];
  while(!q.empty()){
    int x=q.front().first,y=q.front().second;
    q.pop();
    //cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++){
      if(table[x+dx[i]][y+dy[i]]==-1) continue;
      if(vis[0][x+dx[i]][y+dy[i]]>max(vis[0][x][y],table[x+dx[i]][y+dy[i]])){
        vis[0][x+dx[i]][y+dy[i]]=max(vis[0][x][y],table[x+dx[i]][y+dy[i]]);
        q.push({x+dx[i],y+dy[i]});
      }
    }
    for(int i=0;i<4;i++){
      if(table[x+dx[i]][y+dy[i]]==-1) continue;
      if(vis[1][x+dx[i]][y+dy[i]]>max(vis[1][x][y],table[x+dx[i]][y+dy[i]])){
        vis[1][x+dx[i]][y+dy[i]]=max(vis[1][x][y],table[x+dx[i]][y+dy[i]]);
        q.push({x+dx[i],y+dy[i]});
      }
    }
    for(int i=0;i<4;i++){
      if(table[x+super_x[i]][y+super_y[i]]==-1) continue;
      if(vis[1][x+super_x[i]][y+super_y[i]]>max(vis[0][x][y],table[x+super_x[i]][y+super_y[i]])){
        vis[1][x+super_x[i]][y+super_y[i]]=max(vis[0][x][y],table[x+super_x[i]][y+super_y[i]]);
        q.push({x+super_x[i],y+super_y[i]});
      }
    }
  }
  cout<<min(vis[0][n][m],vis[1][n][m])<<endl;
}
