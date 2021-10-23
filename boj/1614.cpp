#include <bits/stdc++.h>
#define endl '\n' // 이걸 빼먹음
using namespace std;
int n,k,a,b,s,vis[401],child[401][401],asdf[401];
vector<int>adj[401];
void dfs(int cur){
  if(vis[cur]) return;
  vis[cur]=1;
  for(auto i:adj[cur]){
    child[cur][i]=1;
    if(!vis[i]) dfs(i);
    for(int j=1;j<=n;j++) child[cur][j]=child[cur][j]|child[i][j];
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(child,0,sizeof(child));
  cin>>n>>k;
  for(int i=0;i<k;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    asdf[b]=1;
  }
  vector<int>start;
  for(int i=1;i<=n;i++)
    if(!asdf[i])start.push_back(i);
  for(auto i:start) {
    memset(vis,0,sizeof(vis));
    dfs(i);
  }
  cin>>s;
  for(int i=0;i<s;i++){
    cin>>a>>b;
    if(child[a][b]) cout<<-1<<endl;
    else if(child[b][a]) cout<<1<<endl;
    else cout<<0<<endl;
  }
}
