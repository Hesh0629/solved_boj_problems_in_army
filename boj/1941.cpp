// 이게 왜돌아가지
// S를 기준으로 DFS를 돌리되, 다음 위치는 BFS 처럼 정한다.
// 그런데 또 돌아가는 방식은 브루트포스에 백트래킹같고,,,
// set에 vector를 넣어도 고유값만 저장가능
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>start;
set<vector<int>>ans;
int vis[7][7], dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
char table[7][7];
void dfs(pair<int,int>cur,int cnt,vector<pair<int,int>>adj,vector<pair<int,int>>history){
  int x=cur.first, y=cur.second;
  if(vis[x][y]) return;
  else if(cnt==7){
    history.push_back({x,y});
    vector<int>v;
    int cnt=0;
    for(auto i:history){
      if(table[i.first][i.second]=='S') cnt++;
      v.push_back(i.first*5+i.second);
    }
    sort(v.begin(),v.end());
    if(cnt>=4)
      ans.insert(v);
  }
  else{
    vis[x][y]=1;
    history.push_back({x,y});
    for(int k=0;k<4;k++) {
      if(table[x+dx[k]][y+dy[k]]!=-1) adj.push_back({x+dx[k],y+dy[k]});
    }
    for(auto i:adj)
      dfs(i,cnt+1,adj,history);
    vis[x][y]=0;
    history.pop_back();
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(table,-1,sizeof(table));
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=5;i++){
    for(int j=1;j<=5;j++) {
      cin>>table[i][j];
      if(table[i][j]=='S') start.push_back({i,j});
    }
  }
  for(auto i:start){
    vector<pair<int,int>>adj,history;
    dfs(i,1,adj,history);
    adj.clear();
    adj.shrink_to_fit();
  }
  cout<<ans.size()<<endl;
}
