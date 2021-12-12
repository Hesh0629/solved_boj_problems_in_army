// 트리의 분리집합을 구하기
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<int>w(10001),adj[10001];
pair<long long int,vector<int>> dp[10001][2];
pair<long long int,vector<int>> dfs(int cur,int pre);
pair<long long int,vector<int>> dfs2(int cur,int pre);
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>n;
  for(int i=1;i<=n;i++) cin>>w[i];
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  auto ans=max(dfs(1,0),dfs2(1,0));
  cout<<ans.first<<endl;
  sort(ans.second.begin(),ans.second.end());
  for(auto i:ans.second)cout<<i<<" ";
}
pair<long long int,vector<int>> dfs(int cur,int pre){
  if(dp[cur][1].first)
    return dp[cur][1];
  dp[cur][1].first=w[cur];
  dp[cur][1].second.push_back(cur);
  for(auto i:adj[cur]){
    if(i==pre)continue;
    auto res =dfs2(i,cur);
    dp[cur][1].first+=res.first;
    dp[cur][1].second.insert(dp[cur][1].second.end(),res.second.begin(),res.second.end());
  }
  return dp[cur][1];
}
pair<long long int,vector<int>>dfs2(int cur,int pre){
  if(dp[cur][0].first)
    return dp[cur][0];
  dp[cur][0].first=0;
  for(auto i:adj[cur]){
    if(i==pre)continue;
    auto res =max(dfs(i,cur),dfs2(i,cur));
    dp[cur][0].first+=res.first;
    dp[cur][0].second.insert(dp[cur][0].second.end(),res.second.begin(),res.second.end());
  }
  return dp[cur][0];
}
