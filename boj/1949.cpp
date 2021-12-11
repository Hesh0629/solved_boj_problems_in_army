// 3개 마을 모두 미선택하는 것보다 중간에 껴있는 마을을 포함하는 것이 값이 더 크다.
// 따라서 임의의 연속된 3개 마을이 연속으로 미선택될 이유가 배제된다.
// 이러면 문제조건이 자연스럽게 만족된다.
#include<bits/stdc++.h>
using namespace std;
int n,vis[10001],vis2[10001];
vector<int>v(10001),adj[10001];
int dfs(int cur,int pre,int level);
int dfs2(int cur,int pre,int level);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i+1];
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout<<max(dfs(1,0,1),dfs2(1,0,1))<<endl;
}

int dfs(int cur,int pre,int level){ // 현재 마을은 우수 마을
  if(vis[cur])return vis[cur];
  long long int ret=v[cur];
  for(auto i:adj[cur]){
    if(i==pre) continue;
    ret+=dfs2(i,cur,level+1);
  }
  vis[cur]=ret;
  return ret;
}
int dfs2(int cur,int pre,int level){ // 현재 마을은 일반 마을
  if(vis2[cur])return vis2[cur];
  long long int ret=0;
  for(auto i:adj[cur]){
    if(i==pre) continue;
    ret+=max(dfs(i,cur,level+1),dfs2(i,cur,level+1));
  }
  vis2[cur]=ret;
  return ret;
}
