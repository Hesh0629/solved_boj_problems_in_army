// 3차원 BFS, queue 순서 주의하기
#include<bits/stdc++.h>
using namespace std;
int n,m,h,init[102][102][102];
int dx[6]={0,0,0,0,-1,1}, dy[6]={-1,1,0,0,0,0}, dz[6]={0,0,-1,1,0,0};
queue<pair<pair<int,int>,pair<int,int>>>q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(init,-1,sizeof(init));
  cin>>m>>n>>h;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=n;j++) {
      for(int k=1;k<=m;k++){
        cin>>init[i][j][k];
        if(init[i][j][k]==1){
          q.push({{i,j},{k,2}});
        }
      }
    }
  }
  while(!q.empty()){
    int z=q.front().first.first, x=q.front().first.second,y=q.front().second.first,day=q.front().second.second;
    q.pop();
    for(int i=0;i<6;i++){
      if(init[z+dz[i]][x+dx[i]][y+dy[i]]==0){
        init[z+dz[i]][x+dx[i]][y+dy[i]]=day;
        q.push({{z+dz[i],x+dx[i]},{y+dy[i],day+1}});
      }
    }
  }
  int  ans=1;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=n;j++) {
      for(int k=1;k<=m;k++){
        ans=max(ans,init[i][j][k]);
        if(init[i][j][k]==0){
          cout<<-1<<endl;
          return 0;
        }
      }
    }
  }
  cout<<ans-1<<endl;
  return 0;
}
