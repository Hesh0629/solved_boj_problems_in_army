#include<bits/stdc++.h>
using namespace std;
long long int dp[101];
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  dp[1]=1;
  dp[2]=2;
  for(int i=3;i<=100;i++){
    dp[i]=dp[i-1]+1;
    for(int j=3;i-j>=0;j++)
      dp[i]=max(dp[i],dp[i-j]*(j-1)); //복붙횟수 저장
  }
  cout<<dp[n]<<endl;
}
