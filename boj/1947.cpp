#include<bits/stdc++.h>
using namespace std;
int n;
long long int dp[1000001],dp2[1000001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(dp2,0,sizeof(dp2));
  cin>>n;
  dp[2]=1;
  dp[3]=2;
  dp2[1]=1;
  dp2[2]=3;
  dp2[3]=dp[3]+3*dp2[2];
  for(int i=4;i<1000001;i++){
    dp[i]=(i-1)*(dp[i-2]+(i-2)*dp2[i-3]%1000000000);
    dp[i]%=1000000000;
    dp2[i]=dp[i]+i*dp2[i-1]%1000000000;
    dp2[i]%=1000000000;
  }
  cout<<dp[n]<<endl;
}
