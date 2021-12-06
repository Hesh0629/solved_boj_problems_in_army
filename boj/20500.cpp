/*
(i-1자리의합+5)%3==0 인경우
=(i-2자리의 합+5)%3==1또는 2인 경우

(i-1자리의합+5)%3==1 인경우
=(i-2자리의 합+5)%3==0또는 2인경우

(i-1자리의합+5)%3==2 인경우
=(i-2자리의 합+5)%3==0또는 1인 경우
*/
#include<bits/stdc++.h>
#define div 1000000007
using namespace std;
int n;
long long dp[1516][4];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  dp[1][0]=1;
  dp[1][1]=1;
  for(int i=2;i<=1515;i++){
    dp[i][0]=(dp[i-1][1]+dp[i-1][2])%div;
    dp[i][1]=(dp[i-1][0]+dp[i-1][2])%div;
    dp[i][2]=(dp[i-1][0]+dp[i-1][1])%div;
  }
  cin>>n;
  cout<<dp[n-1][0]%div<<endl;
}
