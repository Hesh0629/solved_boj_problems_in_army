#include<bits/stdc++.h>
#define div 1000000007
using namespace std;
long long int n;
long long int dp[1001][3][4]; // 2의 개수 상관 X dp[길이][연속개수][연속합]
long long int dp2[1001][3][4];// 2인 블럭이 없는 dp[길이][연속개수][연속합]
long long int ans=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(dp2,0,sizeof(dp2));
  dp[1][0][0]=1;
  dp[2][0][0]=1;
  dp[2][1][1]=1;
  dp[2][1][2]=1;
  dp2[1][0][0]=1;
  dp2[2][0][0]=1;
  dp2[2][1][1]=1;
  for(int i=3;i<=1000;i++){
    dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][1]+dp[i-1][1][2]+dp[i-1][2][0]+dp[i-1][2][1]+dp[i-1][2][2]+dp[i-1][2][3])%div;
    dp[i][1][1]=dp[i-1][0][0]%div;
    dp[i][1][2]=dp[i-1][0][0]%div;
    dp[i][2][2]=dp[i-1][1][1]%div;
    dp[i][2][3]=(dp[i-1][1][1]+dp[i-1][1][2])%div;

    dp2[i][0][0]=(dp2[i-1][0][0]+dp2[i-1][1][1]+dp2[i-1][2][2])%div;
    dp2[i][1][1]=(dp2[i-1][0][0])%div;
    dp2[i][2][2]=(dp2[i-1][1][1])%div;
  }
  cin>>n;
  // 2의 개수를 상관하지 않은 dp배열의 합에서 2가 없는 dp배열의 합을 빼주면 답이 나온다.
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
      ans+=(dp[n][i][j]-dp2[n][i][j])%div;
      ans%=div;
    }
  }
  cout<<ans%div;
}
