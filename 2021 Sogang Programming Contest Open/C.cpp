#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,x,y,vis[1001][1001];
vector<int>adj[1001];
set<int>ans;
void dfs(int cur,int cnt){
  if(vis[cur][cnt])return;
  vis[cur][cnt]=1;
  if(cnt==y){
    ans.insert(cur);
    return;
  }
  for(auto i:adj[cur]) dfs(i,cnt+1);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  cin>>n>>m>>x>>y;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(x,0);
  if(ans.size()==0)cout<<-1<<endl;
  else{
    for(auto it=ans.begin();it!=ans.end();it++)
      cout<<*it<<" ";
  }
}
