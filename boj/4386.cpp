#include<bits/stdc++.h>
using namespace std;
int n,vis[101];
long double a,b,ans=0;
vector<pair<long double,long double>>v;
vector<pair<long double,int>>adj[101];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    v.push_back({a,b});
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        long double dist=(long double)sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second));
        adj[i].push_back({dist,j});
      }
    }
  }
  priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>>pq;
  for(auto i:adj[0])pq.push(i);
  vis[0]=1;
  while(!pq.empty()){
    long double dist=pq.top().first;
    int dest=pq.top().second;
    pq.pop();
    if(vis[dest])continue;
    vis[dest]=1;
    ans+=dist;
    for(auto i:adj[dest]){
      // 이미 방문하지 않은 노드만 추가시켜서 시간 단축시키기!
      if(vis[i.second]==0) pq.push(i);
    }
  }
  cout<<fixed;
  cout.precision(3);
  cout<<ans<<endl;
}
