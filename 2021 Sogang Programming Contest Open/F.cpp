// 0번방을 탈출구로 설정한 후 MST제작
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int n,m,a,b,c,vis[200001];
vector<pair<long long int,long long int>>adj[200001];
priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }
  for(int i=1;i<=n;i++){
    cin>>a;
    adj[i].push_back({a,0});
    adj[0].push_back({a,i});
  }
  pq.push({0,0});
  long long int ans=0;
  while(!pq.empty()){
    long long int dist=pq.top().first;
    long long int cur=pq.top().second;
    pq.pop();
    if(vis[cur]==1)continue;
    vis[cur]=1;
    ans+=dist;
    for(auto k:adj[cur]){
      if(vis[k.second]==0)
        pq.push({k.first,k.second});
    }
  }
  cout<<ans;
}
