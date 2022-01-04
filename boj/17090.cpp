#include<bits/stdc++.h>
using namespace std;
char table[502][502];
int vis[502][502],dp[502][502],n,m;
int dfs(int x,int y){
  if(vis[x][y]) return dp[x][y];
  if(table[x][y]==-1)return 1;
  vis[x][y]=1;
  if(table[x][y]=='U'){
    if(table[x-1][y]==-1){
      dp[x][y]=1;
      return dp[x][y];
    }
    else dp[x][y]=dfs(x-1,y);
  }
  else if(table[x][y]=='R'){
    if(table[x][y+1]==-1){
      dp[x][y]=1;
      return dp[x][y];
    }
    else dp[x][y]=dfs(x,y+1);
  }
  else if(table[x][y]=='L'){
    if(table[x][y-1]==-1){
      dp[x][y]=1;
      return dp[x][y];
    }
    else dp[x][y]=dfs(x,y-1);
  }
  else{
    if(table[x+1][y]==-1){
      dp[x][y]=1;
      return dp[x][y];
    }
    else dp[x][y]=dfs(x+1,y);
  }
  return dp[x][y];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(table,-1,sizeof(table));
  memset(vis,0,sizeof(vis));
  memset(dp,0,sizeof(dp));
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)cin>>table[i][j];
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(dfs(i,j))ans++;
    }
  }
  cout<<ans<<endl;
}
