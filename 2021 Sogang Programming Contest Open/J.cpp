#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int hr,hc,r,c,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
char world[1002][1002],ans[1002][1002];
string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(world,-1,sizeof(world));
  memset(ans,'#',sizeof(ans));
  cin>>r>>c;
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      cin>>world[i][j];
    }
  }
  cin>>hr>>hc;
  cin>>s;
  for(auto asdf:s){
    if(asdf=='U')hr--;
    else if(asdf=='D')hr++;
    else if(asdf=='L')hc--;
    else if(asdf=='R')hc++;
    else if(asdf=='W'){
      if(ans[hr][hc]=='.')continue;
      queue<pair<int,int>>q;
      q.push({hr,hc});
      ans[hr][hc]='.';
      while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
          if(world[x+dx[i]][y+dy[i]]==world[hr][hc]&&ans[x+dx[i]][y+dy[i]]=='#'){
            ans[x+dx[i]][y+dy[i]]='.';
            q.push({x+dx[i],y+dy[i]});
          }
        }
      }
    }
  }
  ans[hr][hc]='.';
  for(int i=0;i<4;i++){
    if(world[hr+dx[i]][hc+dy[i]]!=-1)ans[hr+dx[i]][hc+dy[i]]='.';
  }
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }
}
