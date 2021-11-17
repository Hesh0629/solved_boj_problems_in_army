#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int table[1002][1002],vis[1002][1002],ans[1002][1002],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int n,m,idx=2;
int mp[1000002];
//먼저 DFS를 돌려서 벽을 뚫었을 시 만나게 되는 공간들을 미리 계산해둔다.
void dfs(int x,int y){
  if(vis[x][y]) return;
  vis[x][y]=1;
  table[x][y]=idx;
  mp[idx]++;
  for(int i=0;i<4;i++){
    if(table[x+dx[i]][y+dy[i]]==0) dfs(x+dx[i],y+dy[i]);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(table,-1,sizeof(table));
  memset(vis,0,sizeof(vis));
  memset(ans,0,sizeof(ans));
  memset(mp,0,sizeof(mp));
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      char input;
      cin>>input;
      table[i][j]=input-'0';
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(vis[i][j]==0 &&table[i][j]==0){
        dfs(i,j);
        idx++;
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(table[i][j]>=2)cout<<0;
      else if (table[i][j]==1){
        set<int>asdf;
        int ret=1;
        // 나중에는 미리 계산해둔 값들만 더하면 된다. (중복만 피해주기)
        for(int k=0;k<4;k++){
          if(table[i+dx[k]][j+dy[k]]>=2&&asdf.find(table[i+dx[k]][j+dy[k]])==asdf.end()){
            ret+=mp[table[i+dx[k]][j+dy[k]]];
            asdf.insert(table[i+dx[k]][j+dy[k]]);
          }
        }
        cout<<ret%10;
      }
    }
    cout<<endl;
  }
  return 0;
}
