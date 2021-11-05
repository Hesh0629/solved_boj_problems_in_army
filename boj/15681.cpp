#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,r,q,a,b,vis[100001],ans[100001];
vector<int>adj[100001],adj2[100001];
void dfs(int pre,int cur){
  if(vis[cur])return;
  vis[cur]=1;
  adj2[pre].push_back(cur);
  for(auto i:adj[cur])
    dfs(cur,i);
}
int dfs2(int cur){
  ans[cur]=1;
  for(auto i:adj2[cur]) ans[cur]+=dfs2(i);
  return ans[cur];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(ans,0,sizeof(ans));
  cin>>n>>r>>q;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0,r);
  dfs2(r);
  for(int i=0;i<q;i++){
    cin>>a;
    cout<<ans[a]<<endl;
  }
}
