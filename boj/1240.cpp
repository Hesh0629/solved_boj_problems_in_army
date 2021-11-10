#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a,b,c,dist[1001][1001],vis[1001];
vector<int>adj[1001];
void dfs(int start,int pre,int cur){
  if(vis[cur]) return;
  vis[cur]=1;
  dist[start][cur]=dist[start][pre]+dist[pre][cur];
  for(auto i:adj[cur]) dfs(start,cur,i);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dist,0,sizeof(dist));
  cin>>n>>m;
  for(int i=0;i<n-1;i++){
    cin>>a>>b>>c;
    dist[a][b]=c;
    dist[b][a]=c;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    memset(vis,0,sizeof(vis));
    dfs(i,i,i);
  }
  for(int i=0;i<m;i++){
    cin>>a>>b;
    cout<<dist[a][b]<<endl;
  }
  return 0;
}
