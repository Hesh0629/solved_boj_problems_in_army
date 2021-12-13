#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n,k,dp[101][101][2]; //dp[n][k][끝자리 수 0|1]
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  dp[1][0][0]=1;
  dp[1][0][1]=1;
  for(int i=2;i<=100;i++){
    for(int j=0;j<=i-1;j++){
      dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
      dp[i][j][1]=dp[i-1][j][0];
      if(j>0)
        dp[i][j][1]+=dp[i-1][j-1][1];
    }
  }
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n>>k;
    cout<<dp[n][k][0]+dp[n][k][1]<<endl;
  }
}
