#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[201][201],dp2[201][201],w,h,x,y,dx[2]={0,1},dy[2]={1,0};
int dfs(int curx,int cury){
  if(dp[curx][cury]) return dp[curx][cury];
  else if(curx==x&&cury==y) return 1;
  else{
    for(int i=0;i<2;i++){
      if(!(curx+dx[i]>x||cury+dy[i]>y)){
        if(dp[curx+dx[i]][cury+dy[i]])
          dp[curx][cury]+=dp[curx+dx[i]][cury+dy[i]]%1000007;
        else
          dp[curx][cury]+=dfs(curx+dx[i],cury+dy[i])%1000007;
      } 
    }
    dp[curx][cury]%=1000007;
    return dp[curx][cury];
  }
}
int dfs2(int curx,int cury){
  if(dp2[curx][cury]) return dp2[curx][cury];
  else if(curx==w&&cury==h) return 1;
  else{
    for(int i=0;i<2;i++){
      if(!(curx+dx[i]>w||cury+dy[i]>h)){
        if(dp2[curx+dx[i]][cury+dy[i]])
          dp2[curx][cury]+=dp2[curx+dx[i]][cury+dy[i]]%1000007;
        else
          dp2[curx][cury]+=dfs2(curx+dx[i],cury+dy[i])%1000007;
      }
    }
    dp2[curx][cury]%=1000007;
    return dp2[curx][cury];
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(dp2,0,sizeof(dp2));
  cin>>w>>h;
  cin>>x>>y;
  long long int ans1=dfs(1,1)%1000007;
  long long int ans2=dfs2(x,y)%1000007;
  cout<<(ans1*ans2)%1000007; // overflow 발생 가능
}
