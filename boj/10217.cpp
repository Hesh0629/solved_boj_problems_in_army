#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,pair<int,int>> pr;
int t,n,m,k;
int dp[101][10001];
vector<pr>adj[101];
priority_queue<pr,vector<pr>,greater<pr>>pq;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int asdf=0;asdf<t;asdf++){
    for(int i=0;i<101;i++){
      for(int j=0;j<10001;j++)dp[i][j]=987654321;
      adj[i].clear();
      adj[i].shrink_to_fit();
    }
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
      int u,v,c,d;
      cin>>u>>v>>c>>d;
      adj[u].push_back({v,{c,d}}); //{next,{cost,dist}}
    }
    pq.push({0,{1,0}}); // {dist,{next, cost}}
    while(!pq.empty()){
      int dist=pq.top().first,cur=pq.top().second.first,cost=pq.top().second.second;
      pq.pop();
      if(dp[cur][cost]<dist)continue;
      for(auto i:adj[cur]){
        if(cost+i.second.first>m)continue;
        if(dp[i.first][cost+i.second.first]>dist+i.second.second){
          dp[i.first][cost+i.second.first]=dist+i.second.second;
          pq.push({dist+i.second.second,{i.first,cost+i.second.first}});
        }
      }
    }
    int ans=987654321;
    for(int i=0;i<=m;i++)ans=min(ans,dp[n][i]);
    if(ans==987654321)cout<<"Poor KCM"<<endl;
    else cout<<ans<<endl;
  }
}
