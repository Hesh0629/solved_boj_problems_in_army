// 어떤 한 그래프에서 '모든 정점으로 가는 경로가 존재하고 유일하다' == Tree
// Lowest Common Ancestor에서 2의 제곱번째 조상만 미리 구해둔다 (희소배열)
// prefix sum으로 루트 노드(1)로부터의 거리를 저장해둬서 현재 노드에서 해당 노드까지 거리 계산을 빠르게
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,vis[100001],anc[100001][100],prefix[100001];
vector<int>v;
vector<pair<int,int>>adj[100001];
int ans;
void dfs(int pre, int cur, int level){
  if(vis[cur])return;
  vis[cur]=1;
  for(int i=0;(int)pow(2,i)<level;i++){
    if(i==0) anc[cur][i]=pre;
    else anc[cur][i]=anc[anc[cur][i-1]][i-1]; 
  }
  for(auto i:adj[cur]){ // first: node / second: dist
    if(!vis[i.first]){
      prefix[i.first]=prefix[cur]+i.second;
      dfs(cur,i.first,level+1);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(anc,-1,sizeof(anc));
  memset(prefix,0,sizeof(prefix));
  cin>>n;
  v.resize(n+1);
  for(int i=1;i<=n;i++) cin>>v[i];
  for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    adj[a].push_back({b,c}); // node, dist
    adj[b].push_back({a,c});
  }
  dfs(1,1,1);
  for(int i=1;i<=n;i++){
    int cur=i,idx,target=i;
    while(1){
      idx=0;
      for(;anc[target][idx]!=-1;idx++){
        if(prefix[cur]-prefix[anc[target][idx]]<=v[i]) continue;
        else break;
      }
      idx--;
      if(idx==-1)break;
      else target=anc[target][idx];
    }
    cout<<target<<endl;
  }
}
