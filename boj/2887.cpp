#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[100001],x,y,z;
long long int vis[100001];
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  cin>>n;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    x.push_back({a,i});
    y.push_back({b,i});
    z.push_back({c,i});
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  sort(z.begin(),z.end());
  pair<long long int,long long int>prex=x[0],prey=y[0],prez=z[0];
  for(int i=1;i<n;i++){
    adj[prex.second].push_back({x[i].first-prex.first,x[i].second}); // dist/ index
    adj[prey.second].push_back({y[i].first-prey.first,y[i].second});
    adj[prez.second].push_back({z[i].first-prez.first,z[i].second});
    // 양방향 간선인거 잊지말자
    adj[x[i].second].push_back({x[i].first-prex.first,prex.second});
    adj[y[i].second].push_back({y[i].first-prey.first,prey.second});
    adj[z[i].second].push_back({z[i].first-prez.first,prez.second});
    prex=x[i];
    prey=y[i];
    prez=z[i];
  }
  priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;
  pq.push({0,0}); // dist/ index
  long long int ans=0;
  while(!pq.empty()){
    long long int dist=pq.top().first, cur=pq.top().second;
    pq.pop();
    if(vis[cur]) continue;
    vis[cur]=1;
    ans+=dist;
    for(auto i:adj[cur]){
        pq.push({i.first,i.second});
    }
  }
  cout<<ans<<endl;
}
