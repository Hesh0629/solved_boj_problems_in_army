#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<long long int,pair<int,int>> pp;
int n,m,k,a,b,c;
long long int dp[10001][21];
vector<pair<int,int>>adj[10001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<10001;i++){
    for(int j=0;j<21;j++) dp[i][j]=9223372036854775800;
  }
  cin>>n>>m>>k;
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  priority_queue<pp,vector<pp>,greater<pp>>q; // {dist / idx}, k
  q.push({0,{1,0}});
  dp[1][0]=0;
  while(!q.empty()){
    long long int dist=q.top().first;
    int cur=q.top().second.first,road=q.top().second.second;
    q.pop();
    if(dist>dp[cur][road]) continue; // 그 사이 값이 바뀔 가능성이 있었다. (,,,)
    for(auto i:adj[cur]){
      if(dp[i.first][road]>dist+i.second){
        dp[i.first][road]=dist+i.second;
        if(i.first!=n)
          q.push({dp[i.first][road],{i.first,road}});
      }
      if(road<k && dp[i.first][road+1]>dist){
        dp[i.first][road+1]=dist;
        if(i.first!=n)
          q.push({dp[i.first][road+1],{i.first,road+1}});
      }
    }
  }
  long long int ans=9223372036854775800;
  for(int road=0;road<=k;road++) ans=min(ans,dp[n][road]);
  cout<<ans<<endl;
}
