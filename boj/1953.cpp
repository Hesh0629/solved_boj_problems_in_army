// 1차적으로 문제잘 안 읽고 2차로 color check제대로 안해서 날려먹음
#include <bits/stdc++.h>
using namespace std;
int n,idx,vis[101],temp[101][101];
vector<int>white,blue,adj[101],group[101];
void dfs(int cur,int color){
  if(vis[cur]) return;
  vis[cur]=1;
  if(color==0){
    blue.push_back(cur);
    color=1;
  }
  else if(color==1){
    white.push_back(cur);
    color=0;
  }
  for(auto i:adj[cur]) dfs(i,color);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(vis,0,sizeof(vis));
  memset(temp,0,sizeof(temp));
  cin>>n;
  for(int i=1;i<=n;i++){
    int num,input;
    cin>>num;
    for(int j=0;j<num;j++){
      cin>>input;
      temp[i][input]=1;
    }
  }
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++){
      if((temp[i][j]==1 &&temp[j][i]==1)){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  for(int i=1;i<=n;i++) {
    if(!vis[i])
      dfs(i,0);
  }
  if(blue.size()==0){
    blue.push_back(white.back());
    white.pop_back();
  }
  if(white.size()==0){
    white.push_back(blue.back());
    white.pop_back();
  }
  sort(blue.begin(),blue.end());
  sort(white.begin(),white.end());
  cout<<blue.size()<<endl;
  for(auto i:blue)cout<<i<<" ";
  cout<<endl;
  cout<<white.size()<<endl;
  for(auto i:white)cout<<i<<" ";
}
