// 단순하게 현재 정점을 몇번 째로 방문했을 때 목적지에 도착할 때 까지 얻을 수 있는 최대값 저장
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[301];
int N,M,K,a,b,c,ans=0,vis[301][301],dp[301][301];
int dfs(int cur,int cnt){
  if(cnt>=M&&cur!=N)return 0;
  if(vis[cur][cnt])return dp[cur][cnt];
  vis[cur][cnt]=1;
  int ret=0;
  for(auto i:adj[cur]){
    int cur=0;
    if(i.first==N&&cnt+1<=M) cur+=i.second;
    else{
      int resDFS=dfs(i.first,cnt+1);
      if(resDFS){
        cur+=i.second;
        cur+=resDFS;
      }
    }
    ret=max(ret,cur);
  }
  dp[cur][cnt]=ret;
  return ret;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(dp,0,sizeof(dp));
  cin>>N>>M>>K;
  for(int i=0;i<K;i++){
    cin>>a>>b>>c;
    if(a<b){
      adj[a].push_back({b,c});
    }
  }
  cout<<dfs(1,1)<<endl;
}
