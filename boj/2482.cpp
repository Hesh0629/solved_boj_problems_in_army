#include<bits/stdc++.h>
#define div 1000000003
using namespace std;
int dp[1001][1001],dp2[1001][1001],n,k;
long long int ans=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(dp2,0,sizeof(dp2));
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    dp[i][0]=1;
    if(i==1)
      dp[i][1]=1;
    else if(i==2)
      dp[i][1]=2;
    else{
      for(int j=1;j<=k;j++){
        dp[i][j]=(dp[i-1][j]+dp[i-2][j-1])%div;
      }
    }
  }
  dp2[1][1]=1;
  dp2[2][1]=1;
  for(int i=3;i<=n;i++){
    dp2[i][1]=1;
    if(i==n)dp2[i][k]=dp2[i-2][k-1];
    else{
      for(int j=2;j<=k;j++)
        dp2[i][j]=(dp2[i-1][j]+dp2[i-2][j-1])%div;
    }
  }
  cout<<(dp[n][k]-dp2[n][k]+div)%div<<endl;
}
