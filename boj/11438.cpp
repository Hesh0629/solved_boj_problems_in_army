#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int>adj[100001];
int n,m,a,b,vis[100001],lca[100001][18],lev[100001];
// 2^17=131,072
void dfs(int cur,int pre,int level){
  if(vis[cur])return;
  vis[cur]=1;
  lev[cur]=level;
  for(int i=0;(int)pow(2,i)<level;i++){
    if(i==0)
      lca[cur][i]=pre;
    else 
      lca[cur][i]=lca[lca[cur][i-1]][i-1];
  }
  for(auto i:adj[cur])
    if(vis[i]==0) dfs(i,cur,level+1);
  return;
}
void find_lca(int a,int b){
  int ans_min=987654321,ans_max=-1;
  //level 맞춰주는 과정도 O(logN)으로 접근해야한다.
  if(lev[a]<lev[b]){
    int cur=b;
    for(int i=17;i>=0;i--){
      if(lca[cur][i]!=-1&&lev[lca[cur][i]]>lev[a]) cur=lca[cur][i];
    }
    cur=lca[cur][0];
    b=cur;
  }
  else if(lev[a]>lev[b]){
    int cur=a;
    for(int i=17;i>=0;i--){
      if(lca[cur][i]!=-1&&lev[lca[cur][i]]>lev[b]) cur=lca[cur][i];
    }
    cur=lca[cur][0];
    a=cur;
  }
  if(a==b){
    cout<<a<<endl;
    return;
  }
  for(int i=17;i>=0;i--){
    if(lca[a][i]!=-1&&lca[a][i]!=lca[b][i]){
      a=lca[a][i];
      b=lca[b][i];
    }
  }
  a=lca[a][0];
  cout<<a<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(lca,-1,sizeof(lca));
  memset(lev,0,sizeof(lev));
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,1,1);
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    find_lca(a,b);
  }
}
