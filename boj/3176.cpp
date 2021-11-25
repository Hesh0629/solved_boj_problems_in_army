//LCA로 최소공통 조상뿐만아니라 트리의 한 정점에서 2^i까지의 최대최소를 저장하자
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<pair<int,int>>adj[100001];
int n,m,a,b,c,vis[100001],lca[100001][18],lev[100001],min_v[100001][18],max_v[100001][18];
// 2^17=131,072
void dfs(int cur,int pre,int dist,int level){
  if(vis[cur])return;
  vis[cur]=1;
  lev[cur]=level;
  for(int i=0;(int)pow(2,i)<level;i++){
    if(i==0){
      lca[cur][i]=pre;
      min_v[cur][i]=dist;
      max_v[cur][i]=dist;
    }
    else {
      lca[cur][i]=lca[lca[cur][i-1]][i-1];
      min_v[cur][i]=min(min_v[cur][i-1],min_v[lca[cur][i-1]][i-1]);
      max_v[cur][i]=max(max_v[cur][i-1],max_v[lca[cur][i-1]][i-1]);
    }
  }
  for(auto i:adj[cur]){
    if(vis[i.first]==0) dfs(i.first,cur,i.second,level+1);
  }
  return;
}
void find_lca(int a,int b){
  int ans_min=987654321,ans_max=-1;
  //level 맞춰주는 과정도 O(logN)으로 접근해야한다.
  if(lev[a]<lev[b]){
    int cur=b;
    for(int i=17;i>=0;i--){
      if(lca[cur][i]!=-1&&lev[lca[cur][i]]>lev[a]){
        ans_min=min(ans_min,min_v[cur][i]);
        ans_max=max(ans_max,max_v[cur][i]);
        cur=lca[cur][i];
      }
    }
    ans_min=min(ans_min,min_v[cur][0]);
    ans_max=max(ans_max,max_v[cur][0]);
    cur=lca[cur][0];
    b=cur;
  }
  else if(lev[a]>lev[b]){
    int cur=a;
    for(int i=17;i>=0;i--){
      if(lca[cur][i]!=-1&&lev[lca[cur][i]]>lev[b]){
        ans_min=min(ans_min,min_v[cur][i]);
        ans_max=max(ans_max,max_v[cur][i]);
        cur=lca[cur][i];
      }
    }
    ans_min=min(ans_min,min_v[cur][0]);
    ans_max=max(ans_max,max_v[cur][0]);
    cur=lca[cur][0];
    a=cur;
  }
  if(a==b){
    cout<<ans_min<<" "<<ans_max<<endl;
    return;
  }
  for(int i=17;i>=0;i--){
    if(lca[a][i]!=-1&&lca[a][i]!=lca[b][i]){
      ans_min=min(ans_min,min_v[a][i]);
      ans_min=min(ans_min,min_v[b][i]);
      ans_max=max(ans_max,max_v[a][i]);
      ans_max=max(ans_max,max_v[b][i]);
      a=lca[a][i];
      b=lca[b][i];
    }
  }
  ans_min=min(ans_min,min_v[a][0]);
  ans_min=min(ans_min,min_v[b][0]);
  ans_max=max(ans_max,max_v[a][0]);
  ans_max=max(ans_max,max_v[b][0]);
  cout<<ans_min<<" "<<ans_max<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(lca,-1,sizeof(lca));
  memset(lev,0,sizeof(lev));
  memset(max_v,-1,sizeof(max_v));
  for(int i=0;i<100001;i++){
    for(int j=0;j<18;j++)min_v[i][j]=987654321;
  }
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  dfs(1,1,0,1);
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    find_lca(a,b);  
  }
}
