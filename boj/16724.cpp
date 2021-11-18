// 사이클 하나당 세이프존 하나면 OK
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[1002][1002];
int n,m,vis[1002][1002],fin[1002][1002],ans=0;
char table[1002][1002];
void dfs(pair<int,int>cur){
  int x=cur.first, y=cur.second;
  if(vis[x][y]){
    if(fin[x][y]) return;
    else{
      ans++;
      return;
    }
  }
  vis[x][y]=1;
  for(auto i:adj[x][y])dfs({i.first,i.second});
  fin[x][y]=1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(fin,0,sizeof(fin));
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++) {
      cin>>table[i][j];
      if(table[i][j]=='U') adj[i][j].push_back({i-1,j});
      else if(table[i][j]=='D') adj[i][j].push_back({i+1,j});
      else if(table[i][j]=='L') adj[i][j].push_back({i,j-1});
      else if(table[i][j]=='R') adj[i][j].push_back({i,j+1});
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(vis[i][j]==0) dfs({i,j});
    }
  }
  cout<<ans<<endl;
}
