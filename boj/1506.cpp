#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int vis[101],ans=0,idx=0;
vector<int>v,adj[101],adj2[101],dfs_order;
priority_queue<int,vector<int>,greater<int>>scc[101];
vector<int>cost(101);
int n;
void dfs2(int cur){
  if(vis[cur])return;
  vis[cur]=1;
  scc[idx].push(cost[cur]);
  for(auto i:adj2[cur]) dfs2(i);
}
void dfs(int cur){
  if(vis[cur]) return;
  vis[cur]=1;
  for(auto i:adj[cur])
    dfs(i); //여기다가 cur을 넣어둠,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
  dfs_order.push_back(cur);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int asdf;
    cin>>asdf;
    cost[i+1]=asdf;
  }
  for(int i=1;i<=n;i++){
    char asdf;
    for(int j=1;j<=n;j++){
      cin>>asdf;
      if(asdf=='1') {
        adj[i].push_back(j);
        adj2[j].push_back(i);
      }
    }
  }
  for(int i=1;i<=n;i++) 
    dfs(i);
  reverse(dfs_order.begin(),dfs_order.end());
  memset(vis,0,sizeof(vis));
  for(auto i:dfs_order){
    dfs2(i);
    if(scc[idx].empty())continue;
    ans+=scc[idx].top();
    idx++;
  }
  cout<<ans<<endl;
  return 0;
}
