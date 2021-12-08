#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n,m,k,vis[1001];
vector<pr>adj[1001];
vector<int>start;
priority_queue<pr,vector<pr>,greater<pr>>pq;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  cin>>n>>m>>k;
  for(int i=0;i<k;i++){
    int init;
    cin>>init;
    pq.push({0,init});
  }
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({w,v});
    adj[v].push_back({w,u});
  }
  long long int ans=0;
  while(!pq.empty()){
    int cost=pq.top().first,cur=pq.top().second;
    pq.pop();
    if(vis[cur])continue;
    vis[cur]=1;
    ans+=cost;
    for(auto i:adj[cur]){
      if(vis[i.second]==0)pq.push(i);
    }
  }
  cout<<ans<<endl;
}
