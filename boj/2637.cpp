// 위상정렬을 떠올렸다면 쉬운 문제
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,vis[101],dp[101];
set<int>comp;
vector<int>dfs_order;
vector<pair<int,int>>adj[101];
queue<pair<int,int>>q;
void dfsForOrder(int cur){
  if(vis[cur])return;
  vis[cur]=1;
  for(auto i:adj[cur]) dfsForOrder(i.first);
  dfs_order.push_back(cur);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(dp,0,sizeof(dp));
  cin>>n>>m;
  for(int i=1;i<n;i++)comp.insert(i);
  for(int i=0;i<m;i++){
    int x,y,k;
    cin>>x>>y>>k;
    if(comp.find(x)!=comp.end())comp.erase(x);
    adj[x].push_back({y,k});
  }
  dfsForOrder(n);
  reverse(dfs_order.begin(),dfs_order.end());
  dp[n]=1;
  for(auto cur:dfs_order){
    for(auto k:adj[cur])
      dp[k.first]+=dp[cur]*k.second;
  }
  for(auto it=comp.begin();it!=comp.end();it++)
    cout<<*it<<" "<<dp[*it]<<endl;
}
