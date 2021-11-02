//dp[day][파스타][그 파스타를 몇 일 먹었는지]
#include <bits/stdc++.h>
#define mod 10000
using namespace std;
int n,k,dp[101][4][4],a,b,daily[101];
bool cmp (pair<int,int>a,pair<int,int>b){
  return a.first<b.first;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(daily,0,sizeof(daily));
  cin>>n>>k;
  for(int i=0;i<k;i++){
    cin>>a>>b;
    daily[a]=b;
  }
  if(!daily[1]) {
    dp[1][1][1]=1;
    dp[1][2][1]=1;
    dp[1][3][1]=1;
  }
  else
    dp[1][daily[1]][1]=1;
  for(int day=2;day<=n;day++){
    if(!daily[day]){
      // dp[day][pasta][1] = sum of dp[day-1][그 파스타를 제외한 나머지 파스타][1,2]
      // dp[day][pasta][2] = dp[day-1][pasta][1];
      dp[day][1][1]=(dp[day-1][2][1]+dp[day-1][2][2]+dp[day-1][3][1]+dp[day-1][3][2])%mod;
      dp[day][1][2]=dp[day-1][1][1];

      dp[day][2][1]=(dp[day-1][1][1]+dp[day-1][1][2]+dp[day-1][3][1]+dp[day-1][3][2])%mod;
      dp[day][2][2]=dp[day-1][2][1];

      dp[day][3][1]=(dp[day-1][2][1]+dp[day-1][2][2]+dp[day-1][1][1]+dp[day-1][1][2])%mod;
      dp[day][3][2]=dp[day-1][3][1];         
    }
    else{
      for(int j=1;j<=3;j++){
        if(j!=daily[day])
          dp[day][daily[day]][1]+=dp[day-1][j][1]+dp[day-1][j][2];
        dp[day][daily[day]][2]=dp[day-1][daily[day]][1];
      }
    }
  }
  cout<<(dp[n][1][1]+dp[n][1][2]+dp[n][2][1]+dp[n][2][2]+dp[n][3][1]+dp[n][3][2])%mod<<endl;
}
