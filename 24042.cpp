#include <bits/stdc++.h>
#define INF 999999999999999
using namespace std;
typedef pair<long long int,long long int> pr;
long long int n,m,vis[100001];
vector<pr>adj[100001];
priority_queue<pr,vector<pr>,greater<>>pq;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fill_n(vis,100001,999999999999999);
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back({b,i});
    adj[b].push_back({a,i});
  }
  pq.push({0,1});
  vis[1]=0;
  while(!pq.empty()){
    long long int cur=pq.top().second,t=pq.top().first;
    pq.pop();
    if(vis[cur]<t)continue;
    for(auto i:adj[cur]){
      long long int nextSig=i.second, asdf=vis[cur]-i.second;
      if(asdf<=0)asdf=i.second;
      else{
        nextSig+=(asdf/m)*m;
        if(asdf%m)nextSig+=m;
      }
      if(vis[i.first]>nextSig){
        vis[i.first]=nextSig;
        if(i.first!=n)
        pq.push({nextSig,i.first});
      }
    }
  }
  cout<<vis[n]<<endl;
} 
