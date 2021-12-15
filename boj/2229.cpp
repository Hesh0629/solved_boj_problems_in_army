// dp[n번째 수까지 조사했을 때][조를 m개로 나눌 때] = 최대값
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001],n,init,ans=INT_MIN;
vector<int>v(1001,0);
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>init;
    v[i]=init;
    for(int j=1;j<=i;j++){
      int minVal=INT_MAX,maxVal=INT_MIN;
      for(int k=i-1;k>=0;k--){
        minVal=min(minVal,v[k+1]);
        maxVal=max(maxVal,v[k+1]);
        dp[i][j]=max(dp[i][j],dp[k][j-1]+maxVal-minVal);
      }
    }
  }
  for(int i=1;i<=n;i++) ans=max(ans,dp[n][i]);
  cout<<ans<<endl;
}
