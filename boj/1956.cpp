#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int vis[401][401],v,e,a,b,c;
vector<pair<int,int>>adj[401];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>v>>e;
  for(int i=0;i<401;i++){
    for(int j=0;j<401;j++)vis[i][j]=INF;
  }
  for(int i=0;i<e;i++){
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
  }
  int ans=INF;
  for(int start=1;start<=v;start++){
    queue<int>q;
    q.push(start);
    while(!q.empty()){
      int cur=q.front();
      q.pop();
      if(start==cur){
        for(auto i:adj[cur]){
          vis[start][i.first]=i.second;
          q.push(i.first);
        }
      }
      else{
        for(auto i:adj[cur]){
          if(vis[start][cur]+i.second<vis[start][i.first]){
            vis[start][i.first]=vis[start][cur]+i.second;
            if(i.first!=start) q.push(i.first);
          }
        }
      }
    }
    ans=min(ans,vis[start][start]);
  }
  if(ans==INF) cout<<-1<<endl;
  else cout<<ans<<endl;
}
