#include<bits/stdc++.h>
using namespace std;
int t,w,dp[1001][31][3],ans=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t>>w;
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=t;i++){
    int tree;
    cin>>tree;
    if(i==1){
      if(tree==1)dp[i][0][1]=1;
      else dp[i][1][2]=1;
      ans=max(dp[i][0][1],ans);
      ans=max(dp[i][1][2],ans);
    }
    else{
      for(int j=0;j<=w;j++){
        if(j==0){
          dp[i][j][1]=dp[i-1][j][1];
          dp[i][j][2]=dp[i-1][j][2];
        }
        else{
          dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][2]);
          dp[i][j][2]=max(dp[i-1][j][2],dp[i-1][j-1][1]);
        }
        dp[i][j][tree]+=1;
        ans=max(dp[i][j][1],ans);
        ans=max(dp[i][j][2],ans);
      }
    }
  }
  cout<<ans<<endl;
}
