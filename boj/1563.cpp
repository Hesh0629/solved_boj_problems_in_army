#include<bits/stdc++.h>
#define div 1000000
using namespace std;
long long int n,dp[1001][2][3]; // 날짜 / 지각횟수 / 연속된 결석일수
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  memset(dp,0,sizeof(dp));
  dp[1][0][0]=1;
  dp[1][1][0]=1;
  dp[1][0][1]=1;
  for(int i=2;i<=n;i++){
    dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2])%div;
    dp[i][0][1]=dp[i-1][0][0]%div;
    dp[i][0][2]=dp[i-1][0][1]%div;
    dp[i][1][0]=(dp[i-1][1][0]+dp[i-1][1][1]+dp[i-1][1][2]+dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2])%div;
    dp[i][1][1]=dp[i-1][1][0]%div;
    dp[i][1][2]=dp[i-1][1][1]%div;
  }
  cout<<(dp[n][0][0]+dp[n][0][1]+dp[n][0][2]+dp[n][1][0]+dp[n][1][1]+dp[n][1][2])%div<<endl;
}
