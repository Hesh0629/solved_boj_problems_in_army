#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,stop[102][102],dp[102][102];
int init1,init2,dx[2]={0,1},dy[2]={1,0};
vector<pair<int,int>>target;
int dfs(pair<int,int>cur,pair<int,int>tar){
  if(cur==tar) return 1;
  else if(stop[cur.first][cur.second]) return 0;
  for(int i=0;i<2;i++){
    if(cur.first+dx[i]<=tar.first && cur.second+dy[i]<=tar.second && stop[cur.first+dx[i]][cur.second+dy[i]]==0){
      if(dp[cur.first+dx[i]][cur.second+dy[i]]) dp[cur.first][cur.second]+=dp[cur.first+dx[i]][cur.second+dy[i]];
      else dp[cur.first][cur.second]+=dfs({cur.first+dx[i],cur.second+dy[i]},tar);
    }
  }
  return dp[cur.first][cur.second];
}
bool cmp(pair<int,int>a,pair<int,int>b){
  if(a.first==b.first) return a.second<b.second;
  return a.first<b.first;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(stop,0,sizeof(stop));
  memset(dp,0,sizeof(dp));
  cin>>n>>m>>a>>b;
  for(int i=0;i<a;i++){
    cin>>init1>>init2;
    target.push_back({init1,init2});
  }
  sort(target.begin(),target.end(),cmp);
  for(int i=0;i<b;i++){
    cin>>init1>>init2;
    stop[init1][init2]=1;
  }
  int ans=1;
  ans*=dfs({1,1},{target.front()});
  pair<int,int>pre=target.front();
  for(int i=1;i<target.size();i++){
    memset(dp,0,sizeof(dp));
    ans*=dfs(pre,target[i]);
    pre=target[i];
  }
  ans*=dfs(target.back(),{n,m});
  cout<<ans<<endl;
  return 0;
}
