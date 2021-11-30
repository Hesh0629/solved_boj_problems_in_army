#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,x,y,z,vis[200001];
vector<pair<int,int>>adj[200001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(1){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<200001;i++){
      adj[i].clear();
      adj[i].shrink_to_fit();
    }
    cin>>m>>n;
    if(n==m&&n==0)break;
    long long int ans=0;
    for(int i=0;i<n;i++){
      cin>>x>>y>>z;
      adj[x].push_back({z,y});
      adj[y].push_back({z,x});
      ans+=z;
    }
    pq.push({0,0});
    while(!pq.empty()){
      int dist=pq.top().first,cur=pq.top().second;
      pq.pop();
      if(vis[cur])continue;
      vis[cur]=1;
      ans-=dist;
      for(auto i:adj[cur]){
        if(vis[i.second]==0)
          pq.push(i);
      }
    }
    cout<<ans<<endl;
  }
}
