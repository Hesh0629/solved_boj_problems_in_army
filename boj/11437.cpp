// 최소 공통 조상을 O(logN)에 찾자
// dp 배열을 이용하여 dp[현재노드][i] = 현재노드의 2^i 번째 위에 있는 조상의 숫자를 저장
// 이런식으로 2의 제곱수만큼 뛰어넘으면 OK
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a,b,vis[50001],par[50001],depth[50001],dp[50001][100];
vector<int>adj[50001];
void dfs(int pre,int cur,int dep){
  if(vis[cur]) return;
  vis[cur]=1;
  depth[cur]=dep;
  if(cur==1)
    for(auto i:adj[cur]) dfs(cur,i,dep+1);
  else{
    par[cur]=pre;
    for(int i=0;(int)pow(2,i)<=dep;i++){
      if(i==0) dp[cur][i]=par[cur];
      else
        dp[cur][i]=dp[dp[cur][i-1]][i-1];
    }
    for(auto i:adj[cur]) dfs(cur,i,dep+1);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(par,0,sizeof(par));
  memset(depth,0,sizeof(depth));
  memset(dp,0,sizeof(dp));
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,1,0);
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    //cout<<"case of "<<a<<" "<<b<<endl;
    if(depth[a]<depth[b]){
      while(depth[a]!=depth[b]){
        int gap=depth[b]-depth[a];
        int up=1;
        for(up=0;(int)pow(2,up)<=gap;up++);
        b=dp[b][--up];
      }
    }
    else if(depth[a]>depth[b]){
      while(depth[a]!=depth[b]){
        int gap=depth[a]-depth[b];
        int up;
        for(up=0;(int)pow(2,up)<=gap;up++);
        a=dp[a][--up];
      }
    }
    if(a==b)
      cout<<a<<endl;
    else{
      while(1) {
        if(dp[a][0]==dp[b][0]){
          cout<<dp[a][0]<<endl;
          break;
        }
        int up;
        for(up=1;(int)pow(2,up)<=depth[a]&&dp[a][up]!=dp[b][up];up++);
        up--;
        a=dp[a][up];
        b=dp[b][up];
      }
    }
  }
}
