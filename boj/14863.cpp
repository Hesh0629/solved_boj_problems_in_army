// 오랜만에 푸는 knapsack 문제
#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int n,k,ans,dp[102][100002];
pair<long long int,long long int>walk[101],bike[101]; // 시간, 비용
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,-INF,sizeof(dp));
  ans=-INF;
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>walk[i].first>>walk[i].second;
    cin>>bike[i].first>>bike[i].second;
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=k;j++){
      if(i==0)
        dp[i][j]=0;
      else{
        if(j-walk[i].first>=0 && j-bike[i].first>=0){
          dp[i][j]=max(dp[i-1][j-walk[i].first]+walk[i].second, dp[i-1][j-bike[i].first]+bike[i].second);
        }
        else if(j-walk[i].first>=0) dp[i][j]=dp[i-1][j-walk[i].first]+walk[i].second;
        else if(j-bike[i].first>=0) dp[i][j]=dp[i-1][j-bike[i].first]+bike[i].second;
        else dp[i][j]=-INF;
      }
    }
  }
  cout<<dp[n][k]<<endl;
}
